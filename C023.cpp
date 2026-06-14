#include <iostream>
#include <string>
#include <iomanip>

class Libro {
private:
  std::string titulo, autor; int anio; double precio;

public:
  Libro(std::string t, std::string a, int an, double p) : titulo(t), autor(a), anio(an), precio(p) {}

  int getAnio() const { return anio; }
  double getPrecio() const { return precio; }
  
  const std::string& getTitulo() const { return titulo; }
  const std::string& getAutor() const { return autor; }

  void setPrecio(double p) {  
    if (p >= 0) precio = 0;
    else std::cout << "Precio invalido.\n";
  }

  void imprimir() const {
    std::cout << "Titulo: " << getTitulo() << "\n";
    std::cout << "Autor : " << getAutor() << "\n";
    std::cout << "Anio  : " << getAnio() << "\n";
    std::cout << std::fixed << std::setprecision(2) << "Precio: $" << getPrecio() << "\n";
  }
};

int main() {
  Libro l1("El Principito", "Antoine de Saint-Exupery", 1943, 12.5);
  l1.imprimir();
}
