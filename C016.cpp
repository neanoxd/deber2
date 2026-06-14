#include <iostream>
#include <iomanip>

class Fecha {
public:
  int dia, mes, anio;

  Fecha() : dia(1), mes(1), anio(2000) {}
  Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
  Fecha(int d, int m) : dia(d), mes(m), anio(2024) {}

  void imprimir() { 
    std::cout << std::setw(2) << std::setfill('0') << dia << "/";
    std::cout << std::setw(2) << std::setfill('0') << mes << "/";
    std::cout << anio << "\n";
  }
};

int main() {
  Fecha f1;
  Fecha f2(15, 6, 1999);
  Fecha f3(22, 3);
  f1.imprimir();
  f2.imprimir();
  f3.imprimir();
}
