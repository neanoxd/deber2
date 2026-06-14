#include <iostream>
#include <iomanip>

class Rectangulo {
private:
  double base, altura;
  
public: 
  Rectangulo(double base, double altura) {
    if (base >= 0) this->base = base;
    else base = 0;
    if (altura >= 0) this->altura = altura;
    else altura = 0;
  }

  void setBase(double base) {
    if (base > 0) this->base = base;
    else std::cout << "Base debe ser positiva.\n";
  }

  void setAltura(double altura) {
    if (altura > 0) this->altura = altura;
    else std::cout << "Altura debe ser positiva.\n";
  }

  double getBase() const { return base; }

  double getAltura() const { return altura; }

  double area() const { return base * altura; }

  void imprimir() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Base: " << getBase() << ", Altura: " << getAltura() << ", " << area() << "\n";
  }

  ~Rectangulo() {}
};

int main() {
  Rectangulo r1(5.0, 3.0);
  r1.imprimir();
  r1.setBase(-1);
  r1.imprimir();
  Rectangulo r2(8.0, 3.0);
  r2.imprimir();
}
