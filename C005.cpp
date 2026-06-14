#include <iostream>
#include <string>
#include <iomanip>

class Estudiante {
public:
  std::string nombre; double nota;

  bool aprobo() { return nota >= 60; }

  static void imprimir(Estudiante arr[], int n) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=== Aprobados ===" << std::endl;
    for (int i = 0; i < n; i++) {
      if (arr[i].aprobo()) std::cout << arr[i].nombre << ": " << arr[i].nota << std::endl;
    }
    std::cout << "=== Reprobados ===" << std::endl;
    for (int i = 0; i < n; i++) {
      if (!arr[i].aprobo()) std::cout << arr[i].nombre << ": " << arr[i].nota << std::endl;
    }
  }
};

int main() {
  Estudiante estudiantes[4] = {
        {"Ana", 85},
        {"Luis", 45},
        {"Carla", 92},
        {"Pedro", 58}
  };
  Estudiante::imprimir(estudiantes, 4);
}
