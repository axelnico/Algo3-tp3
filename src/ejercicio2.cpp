#include "ejercicio2.h"
#include "ejercicio1.h"

using namespace std;

tuple<int, int, vector<int> > solverEj2(vector<Estacion> &estaciones, vector<vector<int> > &distancias, int n, int m, int k){ // n == gimnasios, m == paradas, k == tam_mochila
  vector<int> camino_nulo;
  tuple<int, int, vector<int> > solucion = make_tuple(-1,-1,camino_nulo);
  if(tiene_solucion(estaciones,k)){   //Poda: 3*nroPokeParadas >= potasTotales para todos los gym  //  O(n+m)
	  vector<Estacion> visitados;
    int id = donde_voy(estaciones, 0, k);
    int index = indice_estacion_con_id(id, estaciones);
    visitados.push_back(estaciones[index]);
    int potasActuales = estaciones[index].potas;
    estaciones.erase(estaciones.begin() + index);
    greedy_capturar_gimnasios(estaciones,distancias,n,m,k,visitados,potasActuales,id,solucion);
  }
  return solucion;
}

void greedy_capturar_gimnasios(vector<Estacion> &estaciones, vector< vector<int> > &distancias, int n, int m, int k, std::vector<Estacion> &visitados, int potasActuales, int id_estacion_actual, tuple<int,int,vector<int> > &soluciones){
  while(!es_solucion(estaciones)) {
    ordenar(estaciones, distancias, id_estacion_actual);
    int id = donde_voy(estaciones, potasActuales, k);
    int index = indice_estacion_con_id(id, estaciones);
    visitados.push_back(estaciones[index]);
    potasActuales += estaciones[index].potas;
    estaciones.erase(estaciones.begin() + index);
    id_estacion_actual = id;
  }
  int distancia = distancia_acumulada(visitados,distancias);
  vector<int> camino;
  for (int u = 0; u < visitados.size(); ++u) {
    camino.push_back(visitados[u].id);
  }
  soluciones = make_tuple(distancia, visitados.size(), camino);
}

void ordenar(vector<Estacion> &estaciones, vector< vector<int> > distancias, int id_estacion_actual){
  vector<int> ids_vistos;
  ids_vistos.push_back(id_estacion_actual);
  for (int i = 0; i < estaciones.size(); ++i) {
    int id_mas_cercano = id_mas_cercano_que_no_viste(distancias[id_estacion_actual], ids_vistos, estaciones);
    ids_vistos.push_back(id_mas_cercano);
    swap(id_mas_cercano, i, estaciones);
  }
}

int id_mas_cercano_que_no_viste(vector<int> &distancias, vector<int> &vistos, vector<Estacion> &estaciones){
  int actual = id_del_max(distancias);
  for (int j = 0; j < distancias.size(); ++j) {
    if ((distancias[j] <= distancias[actual]) && !esta(vistos, j) && (indice_estacion_con_id(j, estaciones) > -1) ) {
      actual = j;
    }
  }
  return actual;
}

void swap(int id_mas_cercano, int i, vector<Estacion> &estaciones){
  Estacion tmp(estaciones[i]);
  int i_estacion_que_quiero = indice_estacion_con_id(id_mas_cercano, estaciones);
  estaciones[i] = estaciones[i_estacion_que_quiero];
  estaciones[i_estacion_que_quiero] = tmp;
}

int indice_estacion_con_id(int id, vector<Estacion> &estaciones) {
  for (int i = 0; i < estaciones.size(); ++i) {
    if (estaciones[i].id == id) {
      return i;
    }
  }
  return -1;
}

int donde_voy(vector<Estacion> estaciones, int potasActuales, int k){
  for (int i = 0; i < estaciones.size(); ++i) {
    if( puede_ganar_gimnasio(estaciones[i],potasActuales) || puede_recibir_potas(estaciones[i],potasActuales,k) ) {
      return estaciones[i].id;
    }
  }
  return -1;
}

bool esta(vector<int> &vistos, int j){
  for (int i = 0; i < vistos.size(); ++i) {
    if (vistos[i] == j) return true;
  }
  return false;
}

int id_del_max(vector<int> &distancias){
  int res = 0;
  int max_actual = -1;
  for (int l = 0; l < distancias.size(); ++l) {
    if (distancias[l] >= max_actual) {
      res = l;
      max_actual = distancias[l];
    }
  }
  return res;
}