#include <iostream>

class Persona {
public:
  std::string nombre; int edad; double altura;

  bool esMayorDeEdad() {
    if (edad >= 18) return true;
    else return false;
  }
  
  std::string saludar() { 
    return "Hola, soy " + nombre + " y tengo " + std::to_string(edad) + " anios.";
  }

  void imprimir() {
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", Altura: " 
      << altura << "m" << std::endl;
    std::cout << "Mayor de edad: " << (esMayorDeEdad() ? "SI" : "NO") << std::endl;
    std::cout << saludar() << std::endl;
  }
};

int main() {
  Persona p1;
  p1.nombre = "Ana";
  p1.edad = 22;
  p1.altura = 1.65;
  p1.imprimir();

  Persona p2;
  p2.nombre = "Eneth";
  p2.edad = 20;
  p2.altura = 1.67;
  p2.imprimir();

  Persona p3;
  p3.nombre = "Emma";
  p3.edad = 15;
  p3.altura = 1.60;
  p3.imprimir();

}
