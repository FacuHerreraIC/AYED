//
// Created by facuh on 8/23/25.
//

#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma.h"

class Circulo : public Forma{
  public:
    void dibujar() const override{
      cout << "Dibujar un circulo."<< endl;
    };
};

#endif //CIRCULO_H
