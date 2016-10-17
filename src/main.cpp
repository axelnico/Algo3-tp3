#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <fstream>
#include <utility>
#include <vector>
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
  return 0;
}