#include <iostream>
#include <string>
#include <iomanip>

class Producto {
protected:
  std::string codigo;
  std::string nombre;
  double precio;
public:
  Producto(std::string c, std::string n, double p) : codigo(c), nombre(n), precio(p) {}
  virtual ~Producto() {}
  virtual std::string getCategoria() const = 0;
  virtual double calcularPrecioFinal() const = 0;
  virtual void imprimir() const {
    std::cout << "[" << codigo << "] " << nombre << " (" << getCategoria() << ") | Precio Base: $" << precio << " | Final: $" << std::fixed << std::setprecision(2) << calcularPrecioFinal() << "\n";
  }
};

class ProductoFisico : public Producto {
private:
  double peso;
  std::string dimensiones;
public:
  ProductoFisico(std::string c, std::string n, double p, double pe, std::string d) : Producto(c, n, p), peso(pe), dimensiones(d) {}
  std::string getCategoria() const override { return "Fisico"; }
  double calcularPrecioFinal() const override { return precio + (peso * 2.0); }
};

class ProductoDigital : public Producto {
private:
  double tamanoMB;
  std::string plataforma;
public:
  ProductoDigital(std::string c, std::string n, double p, double mb, std::string plat) : Producto(c, n, p), tamanoMB(mb), plataforma(plat) {}
  std::string getCategoria() const override { return "Digital"; }
  double calcularPrecioFinal() const override { return precio * 0.85; }
};

class ProductoSuscripcion : public Producto {
private:
  int periodoMeses;
  bool renovacionAutomatica;
public:
  ProductoSuscripcion(std::string c, std::string n, double p, int meses, bool ra) : Producto(c, n, p), periodoMeses(meses), renovacionAutomatica(ra) {}
  std::string getCategoria() const override { return "Suscripcion"; }
  double calcularPrecioFinal() const override { return precio * periodoMeses; }
};

class Inventario {
private:
  Producto* items[100];
  int cantidad;
public:
  Inventario() : cantidad(0) {}
  ~Inventario() {
    for (int i = 0; i < cantidad; ++i) delete items[i];
  }
  void agregar(Producto* p) {
    if (cantidad < 100) items[cantidad++] = p;
  }
  void imprimir() const {
    for (int i = 0; i < cantidad; ++i) items[i]->imprimir();
  }
  double valorTotal() const {
    double total = 0;
    for (int i = 0; i < cantidad; ++i) total += items[i]->calcularPrecioFinal();
    return total;
  }
};

int main() {
  Inventario inv;
  inv.agregar(new ProductoFisico("P01", "Laptop", 1000, 2.5, "15x10"));
  inv.agregar(new ProductoDigital("P02", "Juego PC", 60, 45000, "Steam"));
  inv.agregar(new ProductoSuscripcion("P03", "Netflix", 15, 12, true));
  inv.imprimir();
  std::cout << "Valor total inventario: $" << inv.valorTotal() << "\n";
}
