#include <iostream>
using namespace std;

class Velocidad {
  public:
    double valor;
    string unidad;

    Velocidad(double v, string u) : unidad(u) {
      valor = (v >= 0) ? v : 0;
    }

    void imprimir() {
      cout << valor << " " << unidad << endl;
    }
};

int main() {
  Velocidad v1(120.0, "km/h");
  Velocidad v2(-50.0, "m/s");
  Velocidad v3(0.0,   "km/h");

  v1.imprimir();
  v2.imprimir();
  v3.imprimir();
}
