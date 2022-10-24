// main
#include <iostream>
#include <Sculptor.h>
#include <string>
using namespace std;
char* TesteEsculptor = "Escultura";
int main()
{
    Sculptor escultura(100,100,100);
    escultura.setColor(296,0,0,0);
    escultura.putVoxel(0,0,0);
    escultura.setColor(100,300,0,0);
    escultura.putBox(2,6,2,6,2,6);
    escultura.cutBox(1,4,1,4,1,4);
    escultura.putSphere(10,20,10,10);
    escultura.cutSphere(10,20,20,10);
    escultura.putEllipsoid(10,20,30,5,3,5);
    escultura.cutEllipsoid(10,15,30,5,3,5);
    escultura.writeOFF(TesteEsculptor);
}
