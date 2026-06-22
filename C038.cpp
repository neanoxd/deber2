#include <iostream>
#include <iomanip>

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
    std::cout << std::left << std::setw(7) << getNombre() << ": ";
    hacerSonido();
  }
};

class Perro : public Animal {
public:
  Perro(std::string n) : Animal(n) {}
  void hacerSonido() const override {
    std::cout << "Guau!\n";
  }
};

class Gato : public Animal {
public:
  Gato(std::string n) : Animal(n) {}
  void hacerSonido() const override {
    std::cout << "Miau!\n";
  }
};

class Pajaro : public Animal {
private:
  std::string msj;
public:
  Pajaro(std::string n, std::string m) : Animal(n), msj(m) {}
  void hacerSonido() const override {
    std::cout << msj << "!" << "\n";
  }
};

int main() {
  Perro p1("Rex");
  Gato g1("Luna");
  Pajaro pa1("Pio", "Pio pio");
  Perro p2("Max");
  Gato g2("Pelusa");
  Pajaro pa2("Loro", "Loro quiere galleta");
  Animal* arr[] = {&p1, &g1, &pa1, &p2, &g2, &pa2};
  for (int i = 0; i < 6; i++) {
    (*arr[i]).imprimir();
  }
}
