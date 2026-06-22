#include <iostream>
#include <string>
#include <cmath>

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
  void imprimir() const override { std::cout << "Circulo Area: " << calcularArea() << "\n"; }
};

class Rectangulo : public Figura {
private:
  double base, altura;
public:
  Rectangulo(double b, double h, std::string c) : Figura(c), base(b), altura(h) {}
  double calcularArea() const override { return base * altura; }
  void imprimir() const override { std::cout << "Rectangulo Area: " << calcularArea() << "\n"; }
};

class Triangulo : public Figura {
private:
  double base, altura;
public:
  Triangulo(double b, double h, std::string c) : Figura(c), base(b), altura(h) {}
  double calcularArea() const override { return (base * altura) / 2.0; }
  void imprimir() const override { std::cout << "Triangulo Area: " << calcularArea() << "\n"; }
};

class Cuadrado : public Figura {
private:
  double lado;
public:
  Cuadrado(double l, std::string c) : Figura(c), lado(l) {}
  double calcularArea() const override { return lado * lado; }
  void imprimir() const override { std::cout << "Cuadrado Area: " << calcularArea() << "\n"; }
};

class Rombo : public Figura {
private:
  double d1, d2;
public:
  Rombo(double diagonal1, double diagonal2, std::string c) : Figura(c), d1(diagonal1), d2(diagonal2) {}
  double calcularArea() const override { return (d1 * d2) / 2.0; }
  void imprimir() const override { std::cout << "Rombo Area: " << calcularArea() << "\n"; }
};

class Lienzo {
private:
  Figura* figuras[50];
  int cantidad;
public:
  Lienzo() : cantidad(0) {}
  ~Lienzo() {
    for (int i = 0; i < cantidad; ++i) delete figuras[i];
  }
  void agregar(Figura* f) {
    if (cantidad < 50) figuras[cantidad++] = f;
  }
  double areaTotalCanvas() const {
    double total = 0;
    for (int i = 0; i < cantidad; ++i) total += figuras[i]->calcularArea();
    return total;
  }
  double areaPromedio() const {
    return cantidad > 0 ? areaTotalCanvas() / cantidad : 0;
  }
  Figura* figuraMayor() const {
    if (cantidad == 0) return nullptr;
    Figura* mayor = figuras[0];
    for (int i = 1; i < cantidad; ++i) {
      if (figuras[i]->calcularArea() > mayor->calcularArea()) mayor = figuras[i];
    }
    return mayor;
  }
  Figura* figuraMenor() const {
    if (cantidad == 0) return nullptr;
    Figura* menor = figuras[0];
    for (int i = 1; i < cantidad; ++i) {
      if (figuras[i]->calcularArea() < menor->calcularArea()) menor = figuras[i];
    }
    return menor;
  }
  void imprimirTodas() const {
    for (int i = 0; i < cantidad; ++i) figuras[i]->imprimir();
  }
};

int main() {
  Lienzo lienzo;
  lienzo.agregar(new Circulo(5.0, "rojo"));
  lienzo.agregar(new Rectangulo(4.0, 6.0, "azul"));
  lienzo.agregar(new Triangulo(3.0, 4.0, "verde"));
  lienzo.agregar(new Cuadrado(5.0, "amarillo"));
  lienzo.agregar(new Rombo(6.0, 8.0, "negro"));
  lienzo.agregar(new Circulo(2.0, "blanco"));
  lienzo.agregar(new Rectangulo(10.0, 2.0, "gris"));
  lienzo.agregar(new Cuadrado(1.0, "celeste"));

  lienzo.imprimirTodas();
  std::cout << "Area total: " << lienzo.areaTotalCanvas() << "\n";
  std::cout << "Area promedio: " << lienzo.areaPromedio() << "\n";
}
