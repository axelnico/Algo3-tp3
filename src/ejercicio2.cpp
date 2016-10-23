#include "ejercicio1.h"

using namespace std;

tuple<int, int, vector<int> > solverEj2(vector<Estacion> &estaciones, const vector<vector<int> > &distancias, int n, int m, int k){ // n == gimnasios, m == paradas, k == tam_mochila
  vector<int> camino_nulo;
  tuple<int, int, vector<int> > solucion = make_tuple(-1,-1,camino_nulo);
  if(tiene_solucion(estaciones,k)){   //Poda: 3*nroPokeParadas >= potasTotales para todos los gym  //  O(n+m)
	  vector<Estacion> visitados;
	  greedy_capturar_gimnasios(estaciones,distancias,n,m,k,visitados,0,solucion);
  }
  return solucion;
}

void greedy_capturar_gimnasios(vector<Estacion> estaciones, const vector< vector<int> > &distancias, int n, int m, int k, std::vector<Estacion> &visitados, int potasActuales, tuple<int,int,vector<int> > &soluciones){
  int id_estacion_actual = 
  ordenar(estaciones, distancias, id_estacion_actual);





  if (es_solucion(estaciones)){ //O(n+m)
    int distancia = distancia_acumulada(visitados,distancias); //O(n+m)
    vector<int> camino;
    for (int i = 0; i < visitados.size(); ++i) { //O(n+m)
      camino.push_back(visitados[i].id);
    }
    soluciones = (make_tuple(distancia, visitados.size(), camino));
  }
  else{
    for (int i = 0; i < estaciones.size(); ++i) { //O(n+m)
      int nueva_distancia = 0;
      if (visitados.size() > 0) {
        int id_ultimo_visitado = visitados.back().id;
        int proxima_distancia = distancias[id_ultimo_visitado][estaciones[i].id];
        nueva_distancia = proxima_distancia + distancia_acumulada(visitados,distancias); //O(n+m)
      }
      if ( (get<0>(soluciones) >= 0 && nueva_distancia < get<0>(soluciones)) || (get<0>(soluciones) < 0) ) {        //Poda: solucion posible no sea peor que solucion actual
        if ( (potasActuales+3 <= k) && (estaciones[i].potas+potasActuales >= 0) ){
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

void ordenar(vector<Estacion> &estaciones, const vector< vector<int> > &distancias, int id_estacion_actual){
  for (int i = 0; i < estaciones.size(); ++i) {
    id_mas_cercano = id_mas_cercano(distancias[id_estacion_actual], i);
    swap(id_mas_cercano, i, estaciones);
  }
}

int id_mas_cercano(vector<int> &distancias, int i){
  for (int j = i; j < distancias.size(); ++j) {
    if (distancias[j] < distancias[actual]) {
      actual = j;
    }
  }
  return j;
}

void swap(int id_mas_cercano, int i, vector<Estacion> &estaciones){
  Estacion tmp(estaciones[i]);
  i_estacion_que_quiero = indice_estacion_con_id(id_mas_cercano, estaciones);
  estaciones[i] = estaciones[i_estacion_que_quiero]:
  estaciones[i_estacion_que_quiero] = tmp;
}

int indice_estacion_con_id(int id, vector<Estacion> &estaciones) {
  for (int i = 0; i < estaciones.size(); ++i) {
    if (estaciones[i].id == id) {
      return i;
    }
  }
  return -1
}