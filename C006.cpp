#include <iostream>
#include <cmath>
#include <iomanip>

class Punto {
public: 
  double x, y;

  double distanciaA(Punto otro) {
    return std::sqrt((x-otro.x)*(x-otro.x) + (y-otro.y)*(y-otro.y));
  }  

  Punto puntoMedio(Punto otro) {
    Punto pm;
    pm.x = (x+otro.x)/2;
    pm.y = (y+otro.y)/2;
    return pm;
  }

  void imprimir(Punto otro) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "P1: (" << x << ", " << y << ")" << std::endl;
    std::cout << "P2: (" << otro.x << ", " << otro.y << ")" << std::endl;
    std::cout << "Distancia: " << distanciaA(otro) << std::endl;
    std::cout << "Punto medio: (" << puntoMedio(otro).x << ", " << puntoMedio(otro).y << ")" << std::endl;
  }
};

int main() {
  Punto P1;
  P1.x = 3;
  P1.y = 4;
  Punto P2;
  P2.x = 7;
  P2.y = 1;
  P1.imprimir(P2);
}
