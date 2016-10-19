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
    vector< tuple <int, int, int> > gimnasios(n);
    for (int i = 0; i < n; i++) {
      int x,y,p;
      cin >> x >> y >> p;
      tuple<int,int,int> gym = make_tuple(x,y,p);
      gimnasios.push_back(gym);
    }
    vector< tuple <int, int> > paradas(m);
    for (int i = 0; i < m; i++) {
      int x,y;
      cin >> x >> y;
      tuple<int,int> pp = make_tuple(x,y);
      paradas.push_back(pp);
    }
  }



  return 0;
}