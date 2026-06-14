#include <iostream>

class Recurso {
public:
  std::string nombre;

  Recurso(std::string n) : nombre(n) { std::cout << nombre << " creado" << "\n"; }
  ~Recurso() { std::cout << nombre << " destruido" << "\n"; }
};

int main() {
  Recurso r1("A");
  {
    Recurso r2("B");
    {
      Recurso r3("C");
    }
  }
}
