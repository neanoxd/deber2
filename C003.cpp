#include <iostream>
#include <cmath>
#include <iomanip>

class Triangulo {
public:
  double lado1, lado2, lado3;

  double calcularPerimetro() { return lado1 + lado2 + lado3; }

  double calcularArea() {
    double s = (lado1+lado2+lado3)/2;
    double area = std::sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
    return area;
  }

  bool esEquilatero() { 
    if (lado1 == lado2 && lado1 == lado3) { return true; }
    else return false;
  }

  bool esRectangulo() {
    if (lado1 == std::sqrt(lado2*lado2+lado3*lado3) or 
      lado2 == std::sqrt(lado1*lado1+lado3*lado3) or 
      lado3 == std::sqrt(lado2*lado2+lado1*lado1)) { return true; }
    else return false;
  }

  void imprimir() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << std::endl;
    std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
    std::cout << "Area: " << calcularArea() << std::endl;
    if (esEquilatero()) std::cout << "Equilatero: SI" << std::endl;
    else std::cout << "Equilatero: NO" << std::endl;
    if (esRectangulo()) std::cout << "Rectangulo: SI" << std::endl; 
    else std::cout << "Rectangulo: NO" << std::endl;
  }
};

int main() {
  Triangulo t1;
  t1.lado1 = 3.0;
  t1.lado2 = 4.0;
  t1.lado3 = 5.0;
  t1.imprimir();
}
