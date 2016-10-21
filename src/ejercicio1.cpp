#include "ejercicio1.h"

using namespace std;

tuple<int, int, vector<int> > solverEj1(vector<Estacion> &estaciones, vector<vector<int> > distancias, int n, int m, int k){
  vector<int> camino_nulo;
  tuple<int, int, vector<int> > solucion = make_tuple(-1,-1,camino_nulo);
  if(tiene_solucion(estaciones){
	  vector<Estacion> visitados;
	  solucion = BT_capturar_gimnasios(estaciones,distancias,n,m,k,visitados);
  }
  return solucion;
}

tuple<int, int, vector<int> > BT_capturar_gimnasios(std::vector<Estacion> &estaciones, vector<vector<int> > distancias, int n, int m, int k, std::vector<Estacion> &visitados, std::tuple<int,int,std::vector<Estacion> > soluciones){
    if (es_solucion(estaciones)){ 
      int distancia = 0;
      for (int i = 0; i < visitados.size() - 1; ++i) {
        distancia += distancias[visitados[i].id][visitados[i+1].id];
      }
      soluciones = (make_tuple(visitados.size(), distancia, visitados));
    }
    else{
      
    }
  
}

bool tiene_solucion(vector<Estacion> &estaciones){
    int potasNecesarias = 0;
    int potasPosibles = 0;
    for (int i = 0; i < estaciones.size(); i++) {
      if(estaciones[i].esGimnasio){
          potasNecesarias += estaciones[i].potas;
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
