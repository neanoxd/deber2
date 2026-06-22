#include <iostream>
#include <string>

class Figura {
public:
  virtual ~Figura() {}
  virtual double calcularArea() const = 0;
  virtual void imprimir() const = 0;
};

class Circulo : public Figura {
private:
  double radio;
public:
  Circulo(double r) : radio(r) {}
  double calcularArea() const override { return 3.14159 * radio * radio; }
  void imprimir() const override { std::cout << "Circulo r=" << radio; }
};

class Rectangulo : public Figura {
private:
  double base;
  double altura;
public:
  Rectangulo(double b, double h) : base(b), altura(h) {}
  double calcularArea() const override { return base * altura; }
  void imprimir() const override { std::cout << "Rectangulo " << base << "x" << altura; }
};

void describir(const Figura& f);

int main() {
  Circulo c(5.0);
  Rectangulo r(4.0, 6.0);
  describir(c);
  describir(r);
}

void describir(const Figura& f) {
  f.imprimir();
  std::cout << " | Area: " << f.calcularArea() << "\n";
}
