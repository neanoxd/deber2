#include <iostream>
using namespace std;

class Volador {
public:
  virtual void volar() {
    cout << "Volando..." << endl;
  }
};

class Nadador {
public:
  virtual void nadar() {
    cout << "Nadando..." << endl;
  }
};

class Pato : public Volador, public Nadador {
private:
  string nombre;

public:
  Pato(string n) : nombre(n) {}

  void volar() override {
    cout << nombre << " vuela: Fiu fiu!" << endl;
  }

  void nadar() override {
    cout << nombre << " nada: Splash!" << endl;
  }
};

class Cisne : public Volador, public Nadador {
private:
  string nombre;

public:
  Cisne(string n) : nombre(n) {}

  void volar() override {
    std::cout << nombre << " vuela: Aleteo elegante.\n";
  }
  
  void nadar() override {
    std::cout << nombre << " nada: Deslizamiento suave.\n";
  }
};

int main() {
  Pato p1("Donald");
  p1.volar();
  p1.nadar();
  Cisne c1("Odette");
  c1.volar();
  c1.nadar();
}
