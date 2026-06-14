#include <iostream>
#include <iomanip>

class Circulo {
public:
  double radio;

  double calcularArea() { return 3.14159 * radio * radio; }
  double calcularPerimetro() { return 2 * 3.14159 * radio; }

  void imprimir() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Radio: " << radio << std::endl;
    std::cout << "Area: " << calcularArea() << std::endl;
    std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
  }
};

int main() {
  Circulo c1;
  c1.radio = 5.0;
  c1.imprimir();
  Circulo c2;
  c2.radio = 3.0;
  c2.imprimir();
}
