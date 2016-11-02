#include "ejercicio2.h"

using namespace std;



//tuple<double, int, vector<int> > 
tuple<double, int, vector<int> > solverEj3(vector<Estacion> estaciones, vector<vector<double> > &distancias, int n, int m, int k);
tuple<double, int, vector<int> > busquedaLocal(vector<int> recorrido, const vector<Estacion> estaciones, vector<vector<double>> &distancias, double distancia, const int cantVertices);
void swap(vector<int> &estado, int i, int j);
vector<vector<int>> dameVecindario (const vector<Estacion> estaciones, const vector<int> estado);
double dameDistancia(const vector<int> recorrido, const vector<vector<double>> distancias);
void imprimirEstado(tuple<double, int, vector<int> > primerEstado);