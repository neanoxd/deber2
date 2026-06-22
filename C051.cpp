#include <iostream>
#include <string>

class Material {
private:
  std::string codigo;
  std::string titulo;
  int anio;
public:
  Material(std::string c, std::string t, int a) : codigo(c), titulo(t), anio(a) {}
  virtual ~Material() {}
  std::string getCodigo() const { return codigo; }
  std::string getTitulo() const { return titulo; }
  int getAnio() const { return anio; }
  virtual std::string getTipo() const = 0;
  virtual bool esPrestable() const = 0;
  virtual void imprimir() const {
    std::cout << "[" << codigo << "] " << getTipo() << ": " << titulo << " (" << anio << ")\n";
  }
};

class Libro : public Material {
private:
  std::string autor;
  int paginas;
public:
  Libro(std::string c, std::string t, int a, std::string au, int p) : Material(c, t, a), autor(au), paginas(p) {}
  std::string getTipo() const override { return "Libro"; }
  bool esPrestable() const override { return true; }
};

class Revista : public Material {
private:
  int numero;
  std::string editorial;
public:
  Revista(std::string c, std::string t, int a, int n, std::string e) : Material(c, t, a), numero(n), editorial(e) {}
  std::string getTipo() const override { return "Revista"; }
  bool esPrestable() const override { return numero >= 50; }
};

class DVD : public Material {
private:
  int duracionMin;
  std::string clasificacion;
public:
  DVD(std::string c, std::string t, int a, int d, std::string cl) : Material(c, t, a), duracionMin(d), clasificacion(cl) {}
  std::string getTipo() const override { return "DVD"; }
  bool esPrestable() const override { return clasificacion != "18+"; }
};

class Biblioteca {
private:
  Material* catalogo[100];
  int cantidad;
public:
  Biblioteca() : cantidad(0) {}
  ~Biblioteca() {
    for (int i = 0; i < cantidad; ++i) delete catalogo[i];
  }
  void agregar(Material* m) {
    if (cantidad < 100) catalogo[cantidad++] = m;
  }
  void listarTodo() const {
    for (int i = 0; i < cantidad; ++i) catalogo[i]->imprimir();
  }
  void listarPrestables() const {
    for (int i = 0; i < cantidad; ++i) {
      if (catalogo[i]->esPrestable()) catalogo[i]->imprimir();
    }
  }
  void buscarPorTitulo(std::string titulo) const {
    for (int i = 0; i < cantidad; ++i) {
      if (catalogo[i]->getTitulo() == titulo) catalogo[i]->imprimir();
    }
  }
};

int main() {
  Biblioteca biblio;
  biblio.agregar(new Libro("L01", "C++ Avanzado", 2024, "Stroustrup", 500));
  biblio.agregar(new Revista("R01", "Tech Monthly", 2010, 45, "TechPress"));
  biblio.agregar(new Revista("R02", "Tech Monthly", 2023, 60, "TechPress"));
  biblio.agregar(new DVD("D01", "Matrix", 1999, 136, "R"));
  biblio.agregar(new DVD("D02", "Horror Night", 2020, 90, "18+"));

  std::cout << "--- Todo ---\n";
  biblio.listarTodo();
  std::cout << "--- Prestables ---\n";
  biblio.listarPrestables();
}
