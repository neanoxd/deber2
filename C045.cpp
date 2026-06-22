#include <iostream>
#include <string>
#include <iomanip>

class Empleado {
protected:
  std::string nombre;
  double salario;
public:
  Empleado(std::string n, double s) : nombre(n), salario(s) {}
  virtual ~Empleado() {}
  std::string getNombre() const { return nombre; }
  double getSalario() const { return salario; }
  virtual double calcularBono() const = 0;
  virtual std::string getTipo() const = 0;
  void imprimir() const {
    std::cout << nombre << " | " << getTipo() << " | $" << std::fixed << std::setprecision(2) << salario << " | Bono: $" << calcularBono() << "\n";
  }
};

class Programador : public Empleado {
public:
  Programador(std::string n, double s) : Empleado(n, s) {}
  double calcularBono() const override { return salario * 0.10; }
  std::string getTipo() const override { return "Programador"; }
};

class Gerente : public Empleado {
public:
  Gerente(std::string n, double s) : Empleado(n, s) {}
  double calcularBono() const override { return salario * 0.20; }
  std::string getTipo() const override { return "Gerente"; }
};

class Director : public Empleado {
public:
  Director(std::string n, double s) : Empleado(n, s) {}
  double calcularBono() const override { return salario * 0.30; }
  std::string getTipo() const override { return "Director"; }
};

int main() {
  Empleado* emp[4];
  emp[0] = new Programador("Ana", 3000.0);
  emp[1] = new Gerente("Luis", 5000.0);
  emp[2] = new Director("Carla", 8000.0);
  emp[3] = new Programador("Pedro", 2800.0);

  double totalBonos = 0.0;
  for (int i = 0; i < 4; ++i) {
    emp[i]->imprimir();
    totalBonos += emp[i]->calcularBono();
  }
  std::cout << "Total bonos: $" << totalBonos << "\n";

  for (int i = 0; i < 4; ++i) {
    delete emp[i];
    emp[i] = nullptr;
  }
}
