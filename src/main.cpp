#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <fstream>
#include <utility>
#include <vector>
#include <tuple>
#include <list>
#include <string>
#include <chrono>
#include "ejercicio1.h"


using namespace std;

static chrono::time_point<chrono::high_resolution_clock> start_time;

void start_timer() {
	start_time = chrono::high_resolution_clock::now();
}

double stop_timer() {
	chrono::time_point<chrono::high_resolution_clock> end_time = chrono::high_resolution_clock::now();
	return double(chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count());
}

int distTrigonometrica(tuple<int, int, int> a, tuple<int, int, int> b);

int main(int argc, char *argv[]) {
	int numeroDeEjercicio = 0;
  bool experimentos = false;
  if (argc == 2) {
    numeroDeEjercicio = atoi(argv[1]);
  }
  else if (argc == 3) {
    numeroDeEjercicio = atoi(argv[1]);
    string exp = argv[2];
    if (exp == "-exp") {
      experimentos = true;
    }
  }
  else {
    cout << "Modo de uso: \n tp3 númeroDeEjercicio \n Opcional luego del número de ejercicio: " << endl;
    cout << "   -exp para experimentos" << endl;
    return -1;
  }

  if (numeroDeEjercicio == 1) {
    cout << "ingrese la cantidad de gimnasios, paradas y el tamaño de la mochila" << endl;
    int n,m,k;
    cin >> n >> m >> k;
    cout << "ingrese en las siguientes " << n << " lineas xg, yg, pg, ubicacion y cantidad de posiones necesarias de los gym" << endl;
    cout << "luego, en las siguientes " << m << " lineas xp, yp ubicacion de las paradas" << endl;
    vector< tuple <int, int, int> > gimnasios_y_paradas(n+m);

    for (int i = 0; i < n; i++) {
      int x,y,p;
      cin >> x >> y >> p;
      p = 0-p;
      tuple<int,int,int> gym = make_tuple(x,y,p);
      gimnasios_y_paradas.push_back(gym);
    }

    for (int i = 0; i < m; i++) {
      int x,y;
      cin >> x >> y;
      tuple<int,int,int> pp = make_tuple(x,y,3);
      gimnasios_y_paradas.push_back(pp);
    }

    int indicesMatriz = gimnasios_y_paradas.size()*m + gimnasios_y_paradas.size();
    vector<int> distancias(indicesMatriz);
    for (int i = 0; i < n+m; ++i) {
      for (int k = i; k < n+m; ++k) {
        distancias[i*gimnasios_y_paradas.size() + k] = distTrigonometrica(gimnasios_y_paradas[i], gimnasios_y_paradas[k]);
      }
    }
    vector<Estacion> estaciones(n+m);
    for (i = 0; i < gimnasios_y_paradas.size(); i++){
      bool esGimnasio = i < n ? true : false;
      int potas = get<2>(gimnasios_y_paradas[i]);
      estaciones[i] = Estacion(esEstado, potas, i);
    }
    tuple<int, int, vector<int> > solverEj1(estaciones, n, m, k);
  }



  return 0;
}


int distTrigonometrica(tuple<int, int, int> a, tuple<int, int, int> b){
  int xa = get<0>(a);
  int ya = get<1>(a);
  int xb = get<0>(b);
  int yb = get<1>(b);
  int x = (xa - xb)*(xa - xb);
  int y = (ya - yb)*(ya - yb);
  return (int) sqrt(x+y);
}
