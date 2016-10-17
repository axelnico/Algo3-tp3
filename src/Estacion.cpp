#include "Estacion.h"

Estacion::Estacion(){
  this->esGimnasio = true;
  this->potas = 0;
  this->id = 0;
}

Estacion::Estacion(bool EsGimnasio, int nroPotas, int Id){
  this->esGimnasio = EsGimnasio;
  this->potas = nroPotas;
  this->id = Id;
}

void Estacion::set_estacion(bool EsGimnasio, int nroPotas, int Id){
  this->esGimnasio = EsGimnasio;
  this->potas = nroPotas;
  this->id = Id;
}