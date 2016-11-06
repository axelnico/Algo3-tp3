#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm> //Sort esta en O(n*Log n) y reverse en O(n)
#include "Estacion.h"

using namespace std;



//tuple<double, int, vector<int> > 
tuple<double, int, vector<int> > solverEj4(vector<Estacion> estaciones, vector<vector<double> > &distancias, int n, int m, int k, int grasp);
bool puedoMeter(const vector<Estacion>& estaciones, const vector<int>& recorrido, const Estacion& nuevaEstacion, const int k);
void ordenarPorCosto(vector<int>& lista, const vector<double> & distancias);
bool puedoMeter(const vector<Estacion>& estaciones, const vector<int>& recorrido, const Estacion& nuevaEstacion, const int k);
void ordenarPorCosto(vector<int>& lista, const vector<double>& distancias);
bool sonTodosPotas(const vector<Estacion> & estaciones);
int random(int limit);

bool pairCompare(const pair<int, double>& firstElem, const pair<int, double>& secondElem);