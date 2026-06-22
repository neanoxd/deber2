#include <iostream>
#include <iomanip>

class Forma {
public:
  virtual ~Forma() {}
  virtual double area() const = 0;
  void imprimir() const {
    std::cout << "Area: " << std::fixed << std::setprecision(2) << area() << "\n";
  }
};

class Cuadrado : public Forma {
private:
  double lado;
public:
  Cuadrado(double l) : lado(l) {}
  double area() const override { return lado * lado; }
};

class Rombo : public Forma {
private:
  double d1;
  double d2;
public:
  Rombo(double diag1, double diag2) : d1(diag1), d2(diag2) {}
  double area() const override { return (d1 * d2) / 2.0; }
};

class Pentagono : public Forma {
private:
  double perimetro;
  double apotema;
public:
  Pentagono(double p, double a) : perimetro(p), apotema(a) {}
  double area() const override { return (perimetro * apotema) / 2.0; }
};

int main() {
  Forma* formas[3];
  formas[0] = new Cuadrado(5.0);
  formas[1] = new Rombo(6.0, 8.0);
  formas[2] = new Pentagono(25.0, 2.7528);

  for (int i = 0; i < 3; ++i) {
    formas[i]->imprimir();
    delete formas[i];
    formas[i] = nullptr;
  }
}
