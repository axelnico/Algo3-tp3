#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <fstream>
#include <utility>
#include <vector>
#include <tuple>
#include <list>
#include <string>
#include "Estacion.h"

using namespace std;



void solverEj3(vector<Estacion> &estaciones, vector<vector<double> > &distancias, int n, int m, int k);
tuple<double, vector<int>> busquedaLocal(vector<int> &recorrido, vector<Estacion> &estaciones, vector<vector<double>> &distancias, double distancia);
void swap(vector<int> &estado, int i, int j);
void dameVecindario (vector<Estacion> estaciones, vector<int> recorrido);
double dameDistancia(vector<int> recorrido, vector<vector<double>> distancias);
