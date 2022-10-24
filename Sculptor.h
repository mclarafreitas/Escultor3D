/**
 * @file  sculptor.h
 * @brief  Definição da classe Scultor e seus respectivos
 *      métodos para desenhar figuras geométricas.
 * @author  Ivamar Roque
 * @author  Maria Clara Freitas
 * @since  15/10/2022
 */

#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
using namespace std;
/**
 * @struct Voxel
 * @brief Estrutura que armazena as informações do Voxel.
 * @details
 */
struct Voxel {
    /**
     * @brief   r é a cor vermelha(red).
     */
  float r;
  /**
   * @brief   g é a cor verde(green).
   */
  float g;
  /**
   * @brief   b é a cor azul(blue).
   */
  float b; // Colors
  /**
   * @brief   a é a Transparência.
   */
  float a;
// Transparency
  /**
   * @brief   isOn armazena se o voxel está incluido ou não.
   */
  bool isOn; // Included or not
};
/**
 * @class   Sculptor sculptor.h
 * @brief   A classe Sculptor que criar uma estrutura voxel.
 * @details
 */
class Sculptor {
protected:
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
    Voxel ***v;// 3D matrix

public:
    /**
     * @brief   Sculptor é o construtor da classe.
     */
  Sculptor(int _nx, int _ny, int _nz); // OK
  /**
   * @brief   ~Sculptor é o destrutor da classe.
   */
  ~Sculptor(); // OK
  /**
   * @brief   setColor define a cor atual da escultura em RGB.
   * @details  escolhe a cor de desenho atual em RGB.
   * recebe um valor de 0 a 1.
   */
  void setColor(float _r, float _g, float _b, float alpha); // OK
  /**
   * @brief   putVoxel coloca um voxel na coordenada (x,y,z) desejada.
   */
  void putVoxel(int x, int y, int z); // OK
  /**
   * @brief   cutVoxel retira um voxel da coordenada (x,y,z) desejada.
   */
  void cutVoxel(int x, int y, int z); // OK
  /**
   * @brief   putBox coloca voxels na posição desejada.
   * @details  putBox coloca voxels na posição desejada.
   * Ficará no intervalo [x0, x1] em x, [y0, y1] em y e [z0, z1] em z.
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1); // OK
  /**
   * @brief   cutBox retira voxels da posição desejada.
   * @details  cutBox retira voxels da posição desejada.
   * retira os voxels no intervalo [x0, x1] em x, [y0, y1] em y e [z0, z1] em z.
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); // OK
  /**
   * @brief   putSphere desenha uma esfera de voxels.
   * @details  desenha uma esfera de voxels no local desejado.
   * a esfera ficará no ponto (xcenter, ycenter, zcenter) e terá um raio.
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius); //
  /**
   * @brief   cutSphere retira a esfera de voxels do local desejado.
   * @details  cutSphere retira a esfera de voxels do local desejado.
   * retira  os voxels percentes à esfera no ponto (xcenter, ycenter, zcenter) e do raio.
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //OK
  /**
   * @brief   putEllipsoid desenha uma elipsoide no local desejado.
   * @details  putEllipsoid desenha uma elipsoide no local desejado.
   * o elipsoide ficará no ponto (xcenter, ycenter, zcenter) e terá raios nos semieixos rx, ry e rz.
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // OK
  /**
   * @brief   cutEllipsoid retira um elipsoide do local desejado.
   * @details cutEllipsoid retira um elipsoide do local desejado.
   * remove o elipsoide nos ponto (xcenter, ycenter, zcenter) e nos raios nos semieixos rx, ry e rz.
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // OK
  /**
   * @brief   writeOFF escreve um arquivo .OFF que pode ser utilizado para vizualizar a escultura 3D em algum software.
   */
  void writeOFF(char* filename);
};
#endif // SCULPTOR_H
