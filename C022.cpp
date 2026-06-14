#include <iostream>
using namespace std;

class Caja {
private:
  int contenido;

public:
  Caja(int c) : contenido(c) {}

  int  getContenido() const { return contenido; }
  void setContenido(int c)  { contenido = c;    }

  int getDoble() const {  
    return contenido*2;            
  }
};

int main() {
  Caja c(10);
  const Caja fija(99);

  cout << c.getContenido() << "\n";    
  c.setContenido(20);          
  cout << fija.getContenido() << "\n";        
}
