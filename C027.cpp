#include <iostream>
#include <iomanip>

class Vector2D {
private:
  double x, y;

public:
  Vector2D(double a, double b) : x(a), y(b) {}

  void setX(double x) { this->x = x; }
  void setY(double y) { this->y = y; }

  void imprimir() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "(" << x << ", " << y << ")\n";
  }
};

int main() {
  Vector2D v1(3.0, 4.0);
  Vector2D v2 = v1;
  std::cout << "Original: ";
  v1.imprimir();
  std::cout << "Copia:    ";
  v2.imprimir();
  v2.setX(10);
  v2.setY(20);
  std::cout << "Original: ";
  v1.imprimir();
  std::cout << "Copia:    ";
  v2.imprimir();
}
