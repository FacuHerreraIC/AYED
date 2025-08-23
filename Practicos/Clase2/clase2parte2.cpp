//
// Created by facuh on 8/14/25.
//
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

class Persona{
public:
    Persona(): edad(0), nombre(std::string("Jhon")) {};
    int edad;
    std::string nombre;
};
class PersonaConst{
  public:
    PersonaConst(): edad(0), nombre(std::string("Jhon")) {}

    PersonaConst(int i, const char * str);;
    int edad;
    std::string nombre;
    void mostrar() {
      std::cout<<"Persona "<<nombre << "con edad: "<<edad<<std::endl;
    }
  private:
    int edad;
    std::string nombre;
}

int main() {
  Persona p1;
  std::cout << p1.edad << std::endl;
  std::cout << p1.nombre << std::endl;
  Persona p1 = Persona();

  Persona *p2 = new Persona();
  std::cout << p2->edad<<std::endl;
  std::cout << p2->nombre<<std::endl;
  std::cout << (*p2).edad <<std::endl;
  std::cout << (*p2).nombre<<std::endl;
  delete p2;

  PersonaConst pc;
  pc = PersonaConst(22, "Robertito");
  pc.mostrar();

  PersonaConst *pc1 = PersonaConst(22,"Robertito");
  pc1->mostrar();
  delete pc1;

  PersonaConst pi;

  return 0;
}