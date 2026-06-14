#include <iostream>
#include <string>

class Persona {
private:
  std::string nombre; int edad; double altura;

public:
  void setNombre(std::string n) { nombre = n; }

  void setEdad(int e) {
    if (0 <= e && e <= 120) edad = e;
    else std::cout << "Edad invalida.\n";
  }

  void setAltura(double h) {
    if (0.5 <= h && h <= 2.5) altura = h;
    else std::cout << "Altura invalida.\n";
  }

  int getEdad() const { return edad; }

  double getAltura() const { return altura; };  

  void imprimir() {
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", Altura: "
      << altura << "m\n";
  }
};

int main() {
  Persona p1;
  p1.setNombre("Ana");
  p1.setEdad(22);
  p1.setAltura(1.65);
  p1.imprimir();
  p1.setEdad(121);
  p1.setAltura(0.4);
  p1.imprimir();
}
