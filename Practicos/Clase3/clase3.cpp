//
// Created by facuh on 8/23/25.
//

#include "Forma.h"
#include "Circulo.h"

void dibujarForma (const Forma& f){
  f.dibujar();
}

int main(){
  Forma f;
  f.dibujar();
  Circulo c;
  c.dibujar();

  dibujarForma(f);
  dibujarForma(c);
  return 0;
}
