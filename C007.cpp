#include <iostream>
#include <iomanip>

class Temperatura {
public:
  double celsius;

  double getCelcius();
  double getFahrenheit();
  double getKelvin();
  void imprimir();
};

double Temperatura::getCelcius() {
  return celsius;
}

double Temperatura::getFahrenheit() {
  return celsius * 9 / 5 + 32;
}

double Temperatura::getKelvin() {
  return celsius + 273.15;
}

void Temperatura::imprimir() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Celsius   : " << getCelcius() << std:: endl;
  std::cout << "Fahrenheit: " << getFahrenheit() << std::endl;
  std::cout << "Kelvin    : " << getKelvin() << std::endl;
}

int main() {
  Temperatura t;
  t.celsius = 100.0;
  t.imprimir();
}
