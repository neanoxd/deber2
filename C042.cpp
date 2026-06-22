// C042
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
    std::cout << color << " | Area: " << std::fixed << std::setprecision(2) << calcularArea() << "\n";
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
    std::cout << "Circulo ";
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
    std::cout << "Rectangulo ";
    Figura::imprimir();
  }
};

int main() {
  Figura* figuras[5];
  figuras[0] = new Circulo(5.0, "Rojo");
  figuras[1] = new Rectangulo(4.0, 3.0, "Azul");
  figuras[2] = new Circulo(2.5, "Verde");
  figuras[3] = new Rectangulo(10.0, 2.0, "Amarillo");
  figuras[4] = new Circulo(1.0, "Blanco");
  
  double totalAreas = 0.0;
  for (int i = 0; i < 5; ++i) {
    figuras[i]->imprimir();
    totalAreas += figuras[i]->calcularArea();
  }
  std::cout << "Area total: " << totalAreas << "\n";
  for (int i = 0; i < 5; ++i) {
    delete figuras[i];
    figuras[i] = nullptr;
  }
}
