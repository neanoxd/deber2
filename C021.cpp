#include <iostream>
#include <string>
#include <iomanip>

class CuentaBancaria {
private:
  std::string titular; double saldo;

public:
  CuentaBancaria(std::string t, double s) : titular(t) {
    if (s >= 0) saldo = s;
    else saldo = 0;
  }

  std::string getTitular() const {
    return titular;
  }

  double getSaldo() const {
    return saldo;
  }

  void depositar(double d) {
    if (d > 0) {
      saldo += d;
      std::cout << std::fixed << std::setprecision(2);
      std::cout << "Deposito: $" << d << ". Saldo: $" << saldo << "\n";
    }
    else std::cout << "Error: monto debe ser positivo.\n";
  }
  
  void retirar(double r) {
    if (r <= saldo) {
      saldo -= r;
      std::cout << "Retiro: $" << r << ". Saldo: $" << saldo << "\n";
    }
    else std::cout << "Error: saldo insuficiente.\n";
  }

  void imprimir() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << getTitular() << ": $" << getSaldo() << "\n";
  }
};

int main() {
  CuentaBancaria c1("Ana Torres", -50.0);
  c1.imprimir();
  c1.depositar(500);
  c1.retirar(200);
  c1.retirar(500);
  c1.depositar(-100);
  c1.imprimir();
}
