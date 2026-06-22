#include <iostream>
#include <string>
#include <iomanip>

class Empleado {
protected:
  std::string nombre;
public:
  Empleado(std::string n) : nombre(n) {}
  virtual ~Empleado() {}
  virtual double calcularSalarioMensual() const = 0;
  virtual double calcularImpuesto() const = 0;
  virtual void imprimir() const {
    std::cout << nombre << " | Bruto: $" << std::fixed << std::setprecision(2) << calcularSalarioMensual() 
              << " | Impuesto: $" << calcularImpuesto() 
              << " | Neto: $" << calcularSalarioMensual() - calcularImpuesto() << "\n";
  }
};

class EmpleadoFijo : public Empleado {
private:
  double salarioBase;
public:
  EmpleadoFijo(std::string n, double sb) : Empleado(n), salarioBase(sb) {}
  double calcularSalarioMensual() const override { return salarioBase; }
  double calcularImpuesto() const override { return salarioBase > 2000 ? salarioBase * 0.15 : salarioBase * 0.10; }
};

class EmpleadoHora : public Empleado {
private:
  int horasSemanales;
  double tarifaHora;
public:
  EmpleadoHora(std::string n, int hs, double th) : Empleado(n), horasSemanales(hs), tarifaHora(th) {}
  double calcularSalarioMensual() const override { return horasSemanales * tarifaHora * 4.0; }
  double calcularImpuesto() const override { return calcularSalarioMensual() * 0.08; }
};

class EmpleadoComision : public Empleado {
private:
  double salarioBase;
  double ventas;
  double pctComision;
public:
  EmpleadoComision(std::string n, double sb, double v, double pct) : Empleado(n), salarioBase(sb), ventas(v), pctComision(pct) {}
  double calcularSalarioMensual() const override { return salarioBase + (ventas * pctComision); }
  double calcularImpuesto() const override { return calcularSalarioMensual() * 0.12; }
};

class Nomina {
private:
  Empleado* lista[50];
  int cantidad;
public:
  Nomina() : cantidad(0) {}
  ~Nomina() {
    for (int i = 0; i < cantidad; ++i) delete lista[i];
  }
  void agregar(Empleado* e) {
    if (cantidad < 50) lista[cantidad++] = e;
  }
  double totalBruto() const {
    double t = 0;
    for (int i = 0; i < cantidad; ++i) t += lista[i]->calcularSalarioMensual();
    return t;
  }
  double totalImpuesto() const {
    double t = 0;
    for (int i = 0; i < cantidad; ++i) t += lista[i]->calcularImpuesto();
    return t;
  }
  double totalNeto() const { return totalBruto() - totalImpuesto(); }
  void imprimirNomina() const {
    for (int i = 0; i < cantidad; ++i) lista[i]->imprimir();
  }
};

int main() {
  Nomina nomina;
  nomina.agregar(new EmpleadoFijo("Ana", 2500));
  nomina.agregar(new EmpleadoHora("Luis", 40, 15));
  nomina.agregar(new EmpleadoComision("Carla", 1000, 5000, 0.10));
  
  nomina.imprimirNomina();
  std::cout << "Total Bruto: $" << nomina.totalBruto() << "\n";
  std::cout << "Total Impuesto: $" << nomina.totalImpuesto() << "\n";
  std::cout << "Total Neto: $" << nomina.totalNeto() << "\n";
}
