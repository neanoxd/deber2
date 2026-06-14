#include <iostream>
#include <string>

class Semaforo {
private:
  std::string estado;

public:
  Semaforo() { estado = "rojo"; }

  void avanzar() {
    if (estado == "rojo") estado = "verde";
    else if (estado == "amarillo") estado = "rojo";
    else estado = "amarillo";
  }

  const std::string& getEstado() const { return estado; }

  void imprimir() const {
    std::cout << "Estado: " << getEstado() << "\n";
  }
};

int main() {
  Semaforo s1;
  s1.imprimir();
  s1.avanzar();
  s1.imprimir();
  s1.avanzar();
  s1.imprimir();
  s1.avanzar();
  s1.imprimir();
  s1.avanzar();
  s1.imprimir();
  s1.avanzar();
  s1.imprimir();
  s1.avanzar();
  s1.imprimir();
  s1.avanzar();
}
