#include <iostream>
#include <string>

class Animal {
protected:
  std::string nombre;

public:
  Animal(std::string nombre) : nombre(nombre) {}

  const std::string& getNombre() const { return nombre; }

  virtual void hacerSonido() const {
    std::cout << getNombre() << " dice: ...\n";
  }

  virtual void imprimir() {
    std::cout << getNombre();
  }
};

class Perro : public Animal {
private:
  std::string raza;

public:
  Perro(std::string n, std::string r) : Animal(n), raza(r) {}

  void hacerSonido() const override {
    std::cout << Animal::getNombre() << " (" << raza << ") dice: Guau!\n";
  }

  void imprimir() override {
    std::cout << Animal::getNombre() << " - Raza: " << raza << "\n";
  }
};

class Gato : public Animal {
private:
  bool esCallejero;

public:
  Gato(std::string n, bool c) : Animal(n), esCallejero(c) {}

  void hacerSonido() const override {
    std::cout << Animal::getNombre() << " (Callejero: ";
    if (esCallejero) std::cout << "Si";
    else std::cout << "No";
    std::cout << ") dice: Miau!\n";
  }

  void imprimir() override {
    std::cout << Animal::getNombre() << " - Callejero: ";
    if (esCallejero) std::cout << "Si\n";
    else std::cout << "No\n";
  }
};

int main() {
  Perro p1("Rex", "Labrador");
  p1.hacerSonido();
  p1.imprimir();
  Gato g1("Luna", false);
  g1.hacerSonido();
  g1.imprimir();
}
