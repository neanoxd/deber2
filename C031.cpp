#include <iostream>
#include <iomanip>

class Persona {
private:
  std::string nombre; int edad;

public: 
  Persona(std::string n, int e) : nombre(n), edad(e) {}

  virtual void imprimir() const {
    std::cout << nombre << " | " << edad << " anios";
  }
};


class Empleado : public Persona {
private:
  std::string empresa; double salario;

public:
  Empleado(std::string n, int e, std::string em, double s) : Persona(n, e), empresa(em), salario(s) {}

  void imprimir() const override {
    Persona::imprimir();
    std::cout << " | Empresa: " << empresa << " | Salario: $" << std::fixed << std::setprecision(2) << salario << "\n";
  }
};

class Estudiante : public Persona {
private:
  std::string carrera; int semestre;

public:
  Estudiante(std::string n, int e, std::string c, int s) : Persona(n, e), carrera(c), semestre(s) {}

  void imprimir() const override {
    Persona::imprimir();
    std::cout << " | Carrera: " << carrera << " | Semestre: " << semestre << "\n";
  }
};

int main() {
  Empleado em("Ana Torres", 28, "USFQ", 2500.0);
  Estudiante es("Luis Mora", 20, "Computacion", 4);
  em.imprimir();
  es.imprimir();
}
