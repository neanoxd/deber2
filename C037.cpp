#include <iostream>
#include <string>
#include <iomanip>

class Empleado {
protected:
  std::string nombre; double salario;

public:
  Empleado(std::string n, double s) : nombre(n), salario(s) {}

  const std::string& getNombre() const { return nombre; }

  double getSalario() const { return salario; }

  virtual double calcularBono() const {
    return 0;
  }

  virtual void imprimir() const {
    std::cout << nombre;
  }
};

class Programador : public Empleado {
private:
  std::string lenguaje;

public: 
  Programador(std::string n, double s, std::string l) : Empleado(n, s), lenguaje(l) {}

  double calcularBono() const override {
    return salario * 0.1;
  }

  void imprimir() const override {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << nombre << " (Programador/" << lenguaje << "): $" << salario << " | Bono: $" << calcularBono() << "\n"; 
  }
};

class Gerente : public Empleado {
private:
  std::string departamento;

public: 
  Gerente(std::string n, double s, std::string d) : Empleado(n, s), departamento(d) {}

  double calcularBono() const override {
    return salario * 0.2;
  }

  void imprimir() const override {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << nombre << " (Gerente/" << departamento << "): $" << salario << " | Bono: $" << calcularBono() << "\n";
  }
};

class Director : public Empleado {
private: 
  double presupuesto;

public:
  Director(std::string n, double s, double p) : Empleado(n, s), presupuesto(p) {}

  double calcularBono() const override {
    return salario * 0.3;
  }

  void imprimir() const override {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << nombre << " (Directora): $" << salario << " | Bono: $" << calcularBono() << " | Ppto: $" << presupuesto << "\n";
  }
};



int main() {
  Programador p1("Ana", 3000, "Python");
  p1.imprimir();
  Gerente g1("Luis", 5000, "Sistemas");
  g1.imprimir();
  Director d1("Carla", 8000, 500000);
  d1.imprimir();
}

