#include <iostream>
#include <cmath>
#include <iomanip>

class Triangulo {
private: 
  double altura, base, hipotenusa;

public:
  Triangulo(double a, double b) : altura(a), base(b) { 
    hipotenusa = std::sqrt(base*base + altura*altura); }

  double getBase() const { return base; }
  double getAltura() const { return altura; }
  double getHipotenusa() const { return hipotenusa; }

  void imprimir() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Base     : " << getBase() << "\n";
    std::cout << "Altura   : " << getAltura() << "\n";
    std::cout << "Hipotenusa: " << getHipotenusa() << "\n";
  }
};

int main() {
  Triangulo t1(4, 3);
  t1.imprimir();
}
