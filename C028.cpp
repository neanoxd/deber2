#include <iostream>
#include <string>
#include <iomanip>

class ItemInventario {
private:
  std::string codigo, nombre; int cantidad; double precio;

public:
  ItemInventario(std::string c, std::string n, int ca, double p) : codigo(c), nombre(n) {
    cantidad = (ca >= 0) ? ca : 0;
    precio = (p >= 0) ? p : 0;
  }

  const std::string& getCodigo() const { return codigo; }
  const std::string& getNombre() const { return nombre; }
  int getCantidad() const { return cantidad; }
  double getPrecio() const { return precio; }

  void setCantidad(int c) {
    if (c >= 0) cantidad = c;
  } 

  void setPrecio(double p) {
    if (p >= 0) precio = p;
  }

  double valorTotal() const { return getCantidad() * getPrecio(); }

  void vender(int n) {
    if (n <= cantidad) {
      cantidad -= n;
      std::cout << "Venta de " << n << " unidades. Quedan: " << cantidad << "\n";
    }
    else std::cout << "Stock insuiciente. Solo hay " << cantidad << " unidades.\n";
  }

  void reabastecer(int n) {
    cantidad += n;
    std::cout << "Reabastecido: +" << n << " unidades. Total: " << cantidad << "\n";
  }

  void imprimir() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "[" << getCodigo() << "] " << getNombre() << " | Cant: " << getCantidad()
      << " | Precio: $" << getPrecio() << " | Total: $" << valorTotal() << "\n";
  }
};

int main() {
  ItemInventario i1("A001", "Laptop", 10, 1200);
  i1.imprimir();
  i1.vender(3);
  i1.vender(10);
  i1.reabastecer(20);
  i1.imprimir();
}
