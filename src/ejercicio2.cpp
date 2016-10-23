#include "ejercicio2.h"
#include "ejercicio1.h"

using namespace std;

tuple<int, int, vector<int> > solverEj2(vector<Estacion> &estaciones, vector<vector<int> > &distancias, int n, int m, int k){ // n == gimnasios, m == paradas, k == tam_mochila
  vector<int> camino_nulo;
  tuple<int, int, vector<int> > solucion = make_tuple(-1,-1,camino_nulo);
  if(tiene_solucion(estaciones,k)){   //Poda: 3*nroPokeParadas >= potasTotales para todos los gym  //  O(n+m)
	  vector<Estacion> visitados;
    int id = donde_voy(estaciones, 0, k);
	  greedy_capturar_gimnasios(estaciones,distancias,n,m,k,visitados,0,id,solucion);
  }
  return solucion;
}

void greedy_capturar_gimnasios(vector<Estacion> estaciones, vector< vector<int> > &distancias, int n, int m, int k, std::vector<Estacion> &visitados, int potasActuales, int id_estacion_actual, tuple<int,int,vector<int> > &soluciones){
  for (int i = 0; i < n+m; ++i) {
    ordenar(estaciones, distancias, id_estacion_actual);
    int id = donde_voy(estaciones, potasActuales, k);
    int index = indice_estacion_con_id(id, estaciones);
    visitados.push_back(estaciones[index]);
    visitados.push_back(estaciones[i]);
    potasActuales += estaciones[i].potas;
    estaciones.erase(estaciones.begin() + i);
  }
  int distancia = distancia_acumulada(visitados,distancias);
  vector<int> camino;
  for (int i = 0; i < visitados.size(); ++i) {
    camino.push_back(visitados[i].id);
  }
  soluciones = make_tuple(distancia, visitados.size(), camino);
}

// bool tiene_solucion(vector<Estacion> &estaciones, int k){
//   int potasNecesarias = 0;
//   int potasPosibles = 0;
//   for (int i = 0; i  < estaciones.size(); i++) {
//     if(estaciones[i].esGimnasio){
//       int potas_gym = estaciones[i].potas;
//       if (k + potas_gym < 0) return false;
//       potasNecesarias += potas_gym;
//     }
//     else{
//       potasPosibles += 3;
//     }
//   }
//   return potasNecesarias <= potasPosibles;
// }

// bool puede_ganar_gimnasio(Estacion &estacion,int potas){
//     return estacion.esGimnasio && estacion.potas+potas >= 0;
// }

// bool puede_recibir_potas(Estacion &estacion,int potas,int tamano_mochila){
//   return (!estacion.esGimnasio) && (potas+3 <= tamano_mochila);
// }

// bool es_solucion(std::vector<Estacion> &estaciones){
//   for (int i = 0; i < estaciones.size(); i++) {
//     if(estaciones[i].esGimnasio) {
//       return false;
//     }
//   }
//   return true;
// }

// int distancia_acumulada(vector<Estacion> &visitados, std::vector<std::vector<int> > &distancias){
//   int distancia = 0;
//   for (int i = 0; i < visitados.size() - 1; ++i) {
//     distancia += distancias[visitados[i].id][visitados[i+1].id];
//   }
//   return distancia;
// }

void ordenar(vector<Estacion> &estaciones, vector< vector<int> > distancias, int id_estacion_actual){
  for (int i = 0; i < estaciones.size(); ++i) {
    int id_mas_cercano = id_mas_cercano_que_no_viste(distancias[id_estacion_actual]);
    swap(id_mas_cercano, i, estaciones);
  }
}

int id_mas_cercano_que_no_viste(vector<int> &distancias){
  int actual = 0;
  for (int j = 0; j < distancias.size(); ++j) {
    if (distancias[j] < distancias[actual]) {
      actual = j;
    }
  }
  distancias.erase(distancias.begin() + actual);
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