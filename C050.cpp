#include <iostream>
#include <string>
#include <iomanip>

class Vehiculo {
protected:
  std::string marca;
  std::string modelo;
  int anio;
  double precioBase;
public:
  Vehiculo(std::string ma, std::string mo, int a, double p) : marca(ma), modelo(mo), anio(a), precioBase(p) {}
  virtual ~Vehiculo() {}
  virtual double calcularCosto() const = 0;
  virtual std::string getTipo() const = 0;
  void imprimir() const {
    std::cout << getTipo() << " " << marca << " " << modelo << " (" << anio << ") | Costo: $" << std::fixed << std::setprecision(2) << calcularCosto() << "\n";
  }
};

class Auto : public Vehiculo {
public:
  Auto(std::string ma, std::string mo, int a, double p) : Vehiculo(ma, mo, a, p) {}
  double calcularCosto() const override { return precioBase + (anio > 2020 ? precioBase * 0.10 : 0.0); }
  std::string getTipo() const override { return "Auto"; }
};

class Moto : public Vehiculo {
public:
  Moto(std::string ma, std::string mo, int a, double p) : Vehiculo(ma, mo, a, p) {}
  double calcularCosto() const override { return precioBase * 0.7; }
  std::string getTipo() const override { return "Moto"; }
};

class Camion : public Vehiculo {
public:
  Camion(std::string ma, std::string mo, int a, double p) : Vehiculo(ma, mo, a, p) {}
  double calcularCosto() const override { return precioBase * 2.5; }
  std::string getTipo() const override { return "Camion"; }
};

int main() {
  Vehiculo* flota[6];
  flota[0] = new Auto("Toyota", "Corolla", 2022, 20000);
  flota[1] = new Moto("Honda", "CBR", 2019, 10000);
  flota[2] = new Camion("Volvo", "FH", 2018, 50000);
  flota[3] = new Auto("Nissan", "Sentra", 2015, 15000);
  flota[4] = new Moto("Yamaha", "R1", 2023, 12000);
  flota[5] = new Camion("Scania", "R450", 2021, 60000);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6 - i - 1; ++j) {
      if (flota[j]->calcularCosto() < flota[j + 1]->calcularCosto()) {
        Vehiculo* temp = flota[j];
        flota[j] = flota[j + 1];
        flota[j + 1] = temp;
      }
    }
  }

  double total = 0.0;
  for (int i = 0; i < 6; ++i) {
    flota[i]->imprimir();
    total += flota[i]->calcularCosto();
    delete flota[i];
    flota[i] = nullptr;
  }
  std::cout << "Costo total de flota: $" << total << "\n";
}
