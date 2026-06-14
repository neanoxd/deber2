#include <iostream>
#include <iomanip>

class Matematica {
public: 
  static int maximo(int a, int b) { if (a > b) return a; else return b; }

  static int minimo(int a, int b) { if (a < b) return a; else return b; }

  static bool esPrimo(int n) { 
    for (int i = 2; i < n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }

  static double potencia(double base, int exp) {
    int num = 1;
    for (int i = 0; i < exp; i++) {
      num *= base;
    }
    return num;
  }
};

int main() {
  std::cout << "Maximo(8, 3): " << Matematica::maximo(8, 3) << std::endl;
  std::cout << "Minimo(8, 3): " << Matematica::minimo(8, 3) << std::endl;
  std::cout << "Es primo 7: ";
  if (Matematica::esPrimo(7)) std::cout << "SI" << std::endl;
  std::cout << "Es primo 9: ";
  if (Matematica::esPrimo(9)) std::cout << "SI" << std::endl;
  else std::cout << "NO" << std::endl;
  std::cout << std::fixed << std::setprecision(1) << "2 elevado a 10: " << Matematica::potencia(2, 10) << std::endl;
}
