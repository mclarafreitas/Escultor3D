#include <iostream>
#include <fstream>
#include <Sculptor.h>
using namespace std;
Voxel*** alocaEspaco(int nc,int na, int nl){
    /*
        A função "alocaespaco" é responsável por alocar o espaço tridimensiona onde será feito a escultura 3D
        Ou seja, irá fazer uma alocação de uma matriz, cada elemento dessa matriz irá receber a "altura" do espaço
        ou seja, de 0 a N onde será possível inserir voxels
    */
    int i,j;
    Voxel ***aux;
    aux = new Voxel**[nl];
    if(aux != 0){       

        aux[0] = new Voxel*[nc*nl];
        if(aux[0]!=0){
            for(i = 1;i < nl; i++){
               aux[i] = aux[i-1] + nc;
            }
        }
        else{
            aux=0;
            return aux;
        }
    }
    else{
        aux = 0;
        return aux;
    }
    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            aux[i][j] = new Voxel[na];
            if(aux[i][j]==0){
                j--;
            }
        }
    }
    return aux;
}
bool validaCord(int x, int y, int z,int nc, int na, int nl){
    if(x>=0 && x<=nc){
        if(y>=0 && y<= na){
            if(z>=0 && z<=nl){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }else{
        return false;
    }
}
bool validaEsfera(int z,int x,int y,int a,int b,int c, int raio){
    int rQrd = raio*raio;
    int aux = (x-a)*(x-a) + (y-b)*(y-b) + (z-c)*(z-c);
    if(aux <= rQrd){
        return true;
    }
    else{
        return false;
    }
}
bool validaElipse(int z,int x,int y,int xcent, int ycent,int zcent,int a,int b,int c){
    int aux = (x-xcent)*(x-xcent)/(float)(a*a) + (y-ycent)*(y-ycent)/(float)(b*b) + (z-zcent)*(z-zcent)/(float)(c*c);
    if(aux <= 1)
        return true;
    else
        return false;
}
// Construtor da classe
Sculptor :: Sculptor(int _nx,int _ny,int _nz){
    v = 0; // faço V apontar para zero para ter um parametro que a alocação da memória ocorreu de forma correta
    nx = _nx; ny = _ny; nz = _nz; // seta os valores das dimensões do espaço 3D
    do {
        v = alocaEspaco(nx,ny,nz); // chamada da função para alocação da memória necesária
    } while (v==0);
    for(int i=0;i<nz;i++){
        for(int j=0;j<nx;j++){
            for(int k=0;k<ny;k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor :: ~Sculptor(){
    delete v[0][0];
    delete v[0];
    delete v; // Libera o espaço da memória antes usado para guardar o espaço de 3D do objeto
    v = 0; // dessa forma posso reutilizar o ponteiro
}
void Sculptor :: setColor(float _r, float _g, float _b, float alpha){
    r = _r; g = _g; b = _b; a = alpha; // seta os valores da cores a serem usadas
}
void Sculptor ::putVoxel(int x, int y, int z){
    v[z][x][y].a = a;
    v[z][x][y].r = r;
    v[z][x][y].g = g;
    v[z][x][y].b = b;
    v[z][x][y].isOn = true;
}
void Sculptor :: cutVoxel(int x, int y, int z){
    v[z][x][y].isOn = false;
}
void Sculptor :: putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i,j,k;
    if(x1>=x0&&y1>=y0&&z1>=z0){
        for(i=z0;i<=z1;i++){
            for(j=x0;j<=x1;j++){
                for(k=y0;k<=y1;k++){
                    if(validaCord(j,k,i,nx,ny,nz)){
                        putVoxel(j,k,i);
                    }
                }
            }
        }
    }
}
void Sculptor :: cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i,j,k;
    if(x1>=x0&&y1>=y0&&z1>=z0){
        for(i=z0;i<=z1;i++){
            for(j=x0;j<=x1;j++){
                for(k=y0;k<=y1;k++){
                    if(validaCord(j,k,i,nx,ny,nz)){
                        cutVoxel(j,k,i);
                    }
                }
            }
        }
    }
}
void Sculptor :: putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    if(validaCord(xcenter,ycenter,zcenter,nx,ny,nz)){
        int i,j,k;
        for(i=0;i<nz;i++){
            for(j=0;j<nx;j++){
                for(k=0;k<ny;k++){
                    if(validaEsfera(i,j,k,xcenter,ycenter,zcenter,radius)){ // verifica se o pixel satisfaz a equação da esfera com os parametros informados
                        putVoxel(j,k,i);
                    }
                }
            }
        }
    }
}
void Sculptor :: cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    if(validaCord(xcenter,ycenter,zcenter,nx,ny,nz)){
        int i,j,k;
        for(i=0;i<nz;i++){
            for(j=0;j<nx;j++){
                for(k=0;k<ny;k++){
                    if(validaEsfera(i,j,k,xcenter,ycenter,zcenter,radius)){ // verifica se o pixel satisfaz a equação da esfera com os parametros informados
                        cutVoxel(j,k,i);
                    }
                }
            }
        }
    }
}
void Sculptor :: putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    if(validaCord(xcenter,ycenter,zcenter,nx,ny,nz)){
        int i,j,k;
        for(i=0;i<nz;i++){
            for(j=0;j<nx;j++){
                for(k=0;k<ny;k++){
                    if(validaElipse(i,j,k,xcenter,ycenter,zcenter,rx,ry,rz)){ // verifica se o pixel satisfaz a equação da esfera com os parametros informados
                        putVoxel(j,k,i);
                    }
                }
            }
        }
    }
}
void Sculptor :: cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    if(validaCord(xcenter,ycenter,zcenter,nx,ny,nz)){
        int i,j,k;
        for(i=0;i<nz;i++){
            for(j=0;j<nx;j++){
                for(k=0;k<ny;k++){
                    if(validaElipse(i,j,k,xcenter,ycenter,zcenter,rx,ry,rz)){ // verifica se o pixel satisfaz a equação da esfera com os parametros informados
                        cutVoxel(j,k,i);
                    }
                }
            }
        }
    }
}
void Sculptor :: writeOFF(char *filename){
    int i,j,k; int ind=0; int n_elementos = 0;int cont = 0;
    ofstream fout;
    fout.open("Escultura.OFF");
    if(!fout.is_open()){
        cout<<"Erro ao criar o arquivo."<<endl;
        exit(1);
    }
    else{
        cout << "Arquivo criado com sucesso." << endl;
    }

    fout << "OFF" << endl;
    for(i=0;i<nz;i++){
        for(j=0;j<nx;j++){
            for(k=0;k<ny;k++){
                if(v[i][j][k].isOn){
                    n_elementos++;
                }
            }
        }
    }
    fout << n_elementos*8 << " " << n_elementos*6 << " " << 0 <<endl;
    for(i=0;i<nz;i++){
        for(j=0;j<nx;j++){
            for(k=0;k<ny;k++){
                if(v[i][j][k].isOn){
                    fout << j - 0.5 << " " << k + 0.5 << " " << i - 0.5 <<endl; // P0
                    fout << j - 0.5 << " " << k - 0.5 << " " << i - 0.5 <<endl; // P1
                    fout << j + 0.5 << " " << k - 0.5 << " " << i - 0.5 <<endl; // P2
                    fout << j + 0.5 << " " << k + 0.5 << " " << i - 0.5 <<endl; // P3
                    fout << j - 0.5 << " " << k + 0.5 << " " << i + 0.5 <<endl; // P4
                    fout << j - 0.5 << " " << k - 0.5 << " " << i + 0.5 <<endl; // P5
                    fout << j + 0.5 << " " << k - 0.5 << " " << i + 0.5 <<endl; // P6
                    fout << j + 0.5 << " " << k + 0.5 << " " << i + 0.5 <<endl; // P7
                }
            }
        }
    }

    fout.precision(2);
    for(i=0;i<nz;i++){
        for(j=0;j<nx;j++){
            for(k=0;k<ny;k++){
                if(v[i][j][k].isOn){
                    ind=cont*8;
                    fout << 4 << " " << ind+0 << " " << ind+3 << " " << ind+2 << " " << ind+1 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl; // face 1
                    fout << 4 << " " << ind+4 << " " << ind+7 << " " << ind+3 << " " << ind+0 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl; // face 2
                    fout << 4 << " " << ind+5 << " " << ind+6 << " " << ind+7 << " " << ind+4 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl; // face 3
                    fout << 4 << " " << ind+6 << " " << ind+2 << " " << ind+3 << " " << ind+7 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl; // face 4
                    fout << 4 << " " << ind+5 << " " << ind+1 << " " << ind+2 << " " << ind+6 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl; // face 5
                    fout << 4 << " " << ind+5 << " " << ind+4 << " " << ind+0 << " " << ind+1 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl; // face 6
                    cont++;
                }
            }
        }
    }
    cout<<"Escultura feita."<<endl;
    fout.close();
}
