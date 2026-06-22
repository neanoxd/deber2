#include <iostream>
#include <iomanip>

class Cuenta {
protected:
  std::string titular; double saldo;

public:
  Cuenta(std::string t, double s) : titular(t) {
    saldo = (s >= 0) ? s : 0;
  }

  const std::string& getTitular() const { return titular; }

  double getSaldo() const { return saldo; }

  virtual void depositar(double d) {
    std::cout << std::fixed << std::setprecision(2);
    saldo += d;
    std::cout << "Deposito: $" << d << ". Saldo: $" << saldo << "\n";
  }

  virtual void retirar(double r) {
    if (saldo >= r) {
      std::cout << std::fixed << std::setprecision(2);
      saldo -= r;
      std::cout << "Retiro: $" << r << ". Saldo: $" << saldo << "\n";
    }
    else std::cout << "Saldo insuficiente para retiro.\n";
  }

  virtual void imprimir() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << titular << ": $" << saldo;
  }
};

class CuentaAhorro : public Cuenta {
private: 
  double tasaInteres;

public:
  CuentaAhorro(std::string t, double s, double ti) : Cuenta(t, s), tasaInteres(ti) {}

  void aplicarInteres() {
    saldo += saldo * tasaInteres / 100;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Interes aplicado. Saldo: $" << saldo << "\n";
  }

  void imprimir() const override {
    std::cout << "[Ahorro] ";
    Cuenta::imprimir();
    std::cout << " | Interes: " << std::fixed << std::setprecision(0) << tasaInteres << "%\n";
  }
};

class CuentaCorriente : public Cuenta {
private:
  double sobregiroMax;

public:
  CuentaCorriente(std::string t, double s, double g) : Cuenta(t, s), sobregiroMax(g) {}

  void retirar(double r) override {
    std::cout << "Retiro: $" << r << ". "; 
    if (saldo-r >= (-sobregiroMax)) {
      std::cout << std::fixed << std::setprecision(2);
      saldo -= r;
      std::cout << "Saldo: " << (saldo>0 ? "$" : "-$") << std::abs(saldo) << "\n";
    } 
    else std::cout << "RECHAZADO: supera limite de sobregiro.\n";
  }

  void imprimir() const override {
    std::cout << "[Corriente] ";
    Cuenta::imprimir();
    std::cout << " | Sobregiro max: $" << std::fixed << std::setprecision(2) << sobregiroMax << "\n";
  }
};

int main() {
  CuentaAhorro c1("Ana", 1000, 5);
  CuentaCorriente c2("Luis", 500, 200);
  c1.imprimir();
  c1.depositar(200);
  c1.aplicarInteres();
  c2.imprimir();
  c2.retirar(600);
  c2.retirar(200);
}
