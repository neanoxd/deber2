#include <iostream>
#include <string>
#include <iomanip>

class Figura {
protected:
  std::string color;
public:
  Figura(std::string c) : color(c) {}
  virtual ~Figura() {}
  virtual double calcularArea() const = 0;
  virtual double calcularPerimetro() const = 0;
  virtual void imprimir() const {
    std::cout << "Color: " << color << " | Area: " << std::fixed << std::setprecision(2) << calcularArea() << " | Perim: " << calcularPerimetro() << "\n";
  }
};

class Circulo : public Figura {
private:
  double radio;
public:
  Circulo(double r, std::string c) : Figura(c), radio(r) {}
  double calcularArea() const override { return 3.14159 * radio * radio; }
  double calcularPerimetro() const override { return 2 * 3.14159 * radio; }
  void imprimir() const override {
    std::cout << "Circulo | Radio: " << radio << " | ";
    Figura::imprimir();
  }
};

class Rectangulo : public Figura {
private:
  double base;
  double altura;
public:
  Rectangulo(double b, double h, std::string c) : Figura(c), base(b), altura(h) {}
  double calcularArea() const override { return base * altura; }
  double calcularPerimetro() const override { return 2 * (base + altura); }
  void imprimir() const override {
    std::cout << "Rectangulo | Base: " << base << " Altura: " << altura << " | ";
    Figura::imprimir();
  }
};

class Triangulo : public Figura {
private:
  double base;
  double altura;
public:
  Triangulo(double b, double h, std::string c) : Figura(c), base(b), altura(h) {}
  double calcularArea() const override { return (base * altura) / 2.0; }
  double calcularPerimetro() const override { return 0.0; }
  void imprimir() const override {
    std::cout << "Triangulo | Base: " << base << " Altura: " << altura << " | ";
    Figura::imprimir();
  }
};

int main() {
  Circulo c(5.0, "rojo");
  Rectangulo r(6.0, 4.0, "azul");
  Triangulo t(3.0, 4.0, "verde");
  c.imprimir();
  r.imprimir();
  t.imprimir();
}
