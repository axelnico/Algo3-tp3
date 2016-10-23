#include "ejercicio1.h"

using namespace std;

tuple<int, int, vector<int> > solverEj1(vector<Estacion> &estaciones, const vector<vector<int> > &distancias, int n, int m, int k){
  vector<int> camino_nulo;
  tuple<int, int, vector<int> > solucion = make_tuple(-1,-1,camino_nulo);
  if(tiene_solucion(estaciones,k)){   //Poda: 3*nroPokeParadas >= potasTotales para todos los gym
	  vector<Estacion> visitados;
	  BT_capturar_gimnasios(estaciones,distancias,n,m,k,visitados,0,solucion);
  }
  return solucion;
}

void BT_capturar_gimnasios(vector<Estacion> estaciones, const vector< vector<int> > &distancias, int n, int m, int k, std::vector<Estacion> &visitados, int potasActuales, tuple<int,int,vector<int> > &soluciones){
  if (es_solucion(estaciones)){
    int distancia = distancia_acumulada(visitados,distancias);
    vector<int> camino;
    for (int i = 0; i < visitados.size(); ++i) {
      camino.push_back(visitados[i].id);
    }
    soluciones = (make_tuple(distancia, visitados.size(), camino));
  }
  else{
    for (int i = 0; i < estaciones.size(); ++i) {
      int nueva_distancia = 0;
      if (visitados.size() > 0) {
        int id_ultimo_visitado = visitados.back().id;
        int proxima_distancia = distancias[id_ultimo_visitado][estaciones[i].id];
        nueva_distancia = proxima_distancia + distancia_acumulada(visitados,distancias);
      }
      if ( (get<0>(soluciones) >= 0 && nueva_distancia < get<0>(soluciones)) || (get<0>(soluciones) < 0) ) {        //Poda: solucion posible no sea peor que solucion actual
        if (puede_ganar_gimnasio(estaciones[i],potasActuales) || puede_recibir_potas(estaciones[i],potasActuales,k)) {
          visitados.push_back(estaciones[i]);
          potasActuales += estaciones[i].potas;
          estaciones.erase(estaciones.begin() + i);
          BT_capturar_gimnasios(estaciones,distancias,n,m,k,visitados,potasActuales,soluciones);
          Estacion ultimaEstacion(visitados.back());
          visitados.pop_back();
          estaciones.insert(estaciones.begin() + i, ultimaEstacion);
        }
      }
    }
  }

}

bool puede_ganar_gimnasio(Estacion &estacion,int potas){
    return estacion.esGimnasio && estacion.potas+potas >= 0;
}

bool puede_recibir_potas(Estacion &estacion,int potas,int tamano_mochila){
  return (!estacion.esGimnasio) && (potas+3 <= tamano_mochila);
}

bool tiene_solucion(vector<Estacion> &estaciones, int k){
  int potasNecesarias = 0;
  int potasPosibles = 0;
  for (int i = 0; i  < estaciones.size(); i++) {
    if(estaciones[i].esGimnasio){
      int potas_gym = estaciones[i].potas;
      if (k + potas_gym < 0) return false;
      potasNecesarias += potas_gym;
    }
    else{
      potasPosibles += 3;
    }
  }
  return potasNecesarias <= potasPosibles;
}


bool es_solucion(std::vector<Estacion> &estaciones){
  for (int i = 0; i < estaciones.size(); i++) {
    if(estaciones[i].esGimnasio) {
      return false;
    }
  }
  return true;
}

int distancia_acumulada(vector<Estacion> &visitados, const std::vector<std::vector<int> > &distancias){
  int distancia = 0;
  for (int i = 0; i < visitados.size() - 1; ++i) {
    distancia += distancias[visitados[i].id][visitados[i+1].id];
  }
  return distancia;
}