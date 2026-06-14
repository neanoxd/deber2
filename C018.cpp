#include <iostream>
#include <iomanip>
#include <string>

class Producto {
public: 
  std::string nombre; double precio; int stock;

  Producto(std::string n, double p, int s) : nombre(n) {
    precio = (p >= 0) ? p : 0;
    stock = (s >= 0) ? s : 0;
  }

  Producto(std::string n, double p) : nombre(n), stock(0) {
    precio = (p <= 0) ? p : 0;
  }

  ~Producto() { std::cout << "Producto " << nombre << " eliminado del sistema\n"; }

  void vender(int cantidad) {
    if (stock >= cantidad) {
      stock -= cantidad;
      std::cout << "Venta exitosa. Stock restante: " << stock << "\n";
    }
    else std::cout << "Stock insuficiente\n";
  }

  void reabastecer(int cantidad) { 
    stock += cantidad; 
    std::cout << "Reabastecer :" << cantidad << " unidades. Stock: " << stock << "\n";
  }

  void imprimir() const {
    std::cout << nombre << " | $" << std::fixed << std::setprecision(2) << precio << " | Stock: " << stock << "\n";
  }
};

int main() {
  Producto p1("Laptop", 1200, 5);
  p1.imprimir();
  p1.vender(2);
  p1.vender(5);
  p1.reabastecer(10);
  p1.imprimir();
}
