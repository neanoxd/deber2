#include <iostream>
#include <iomanip>
#include <string>

class Cuenta {
public:
  std::string titular; double saldo;

  bool tieneSaldo(double monto) {
    if (saldo >= monto) return true;
    return false;
  }


  void depositar(double monto) { 
    saldo += monto; 
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Deposito: $" << monto << " | Nuevo saldo: $" << saldo << std::endl;
  }

  void retirar(double monto) { 
    if (tieneSaldo(monto)) {
      saldo -= monto; 
      std::cout << std::fixed << std::setprecision(2);
      std::cout << "Retiro: $" << monto << " | Nuevo saldo: $" << saldo << std::endl;
    }
    else std::cout << "Saldo insuficiente." << std::endl;
  }

  void imprimir() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Titular: " << titular << " | Saldo: $" << saldo << std::endl;
  }
};

int main() {
  Cuenta c1;
  c1.titular = "Ana Torres";
  c1.saldo = 500;
  c1.imprimir();
  c1.depositar(200);
  c1.retirar(100);
  c1.retirar(700);
  c1.imprimir();
}
