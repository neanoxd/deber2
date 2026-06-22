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
  virtual void imprimir() const = 0;
};

class Circulo : public Figura {
private:
  double radio;
public:
  Circulo(double r, std::string c) : Figura(c), radio(r) {}
  double calcularArea() const override { return 3.14159 * radio * radio; }
  void imprimir() const override {
    std::cout << "Circulo (r=" << std::fixed << std::setprecision(2) << radio << "): Area=" << calcularArea() << "\n";
  }
};

class Rectangulo : public Figura {
private:
  double base;
  double altura;
public:
  Rectangulo(double b, double h, std::string c) : Figura(c), base(b), altura(h) {}
  double calcularArea() const override { return base * altura; }
  void imprimir() const override {
    std::cout << "Rect (" << std::fixed << std::setprecision(2) << base << "x" << altura << "): Area=" << calcularArea() << "\n";
  }
};

Figura* crearFigura(std::string tipo, double a, double b);

int main() {
  std::string tipo;
  double a, b;
  while (std::cin >> tipo >> a >> b) {
    Figura* f = crearFigura(tipo, a, b);
    if (f) {
      f->imprimir();
      delete f;
    }
  }
}

Figura* crearFigura(std::string tipo, double a, double b) {
  if (tipo == "circulo") return new Circulo(a, "rojo");
  if (tipo == "rectangulo") return new Rectangulo(a, b, "azul");
  return nullptr;
}
