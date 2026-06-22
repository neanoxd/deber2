#include <iostream>
#include <iomanip>

class Figura {
protected:
  double area;
public:
  Figura() : area(0) {}

  virtual void imprimir() const {
    std::cout << "Figura: " << area << "\n";
  }
};

class Rectangulo : public Figura {
protected:
  double base, altura;
public:
  Rectangulo(double b, double a) : base(b), altura(a) {
    area = base * altura;
  }
 
  void imprimir() const override {
    Figura::imprimir();
    std::cout << "Base: " << base << " Altura: " << altura << "\n";
  }
};

class Cuadrado : public Rectangulo {
protected:
  double lado;

public:
  Cuadrado(double b, double a, double l) : Rectangulo(b, a), lado(l) {}

  void imprimir() const override {
    std::cout << std::fixed << std::setprecision(2);
    Rectangulo::imprimir();
    std::cout << "Lado: " << lado << "\n";
  }
};

int main() {
  Cuadrado c1(5.0, 5.0, 5.0);
  c1.imprimir();
}
