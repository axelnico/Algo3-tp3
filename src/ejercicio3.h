#include "ejercicio2.h"

using namespace std;



tuple<double, int, vector<int> > solverEj3(vector<Estacion> &estaciones, vector<vector<double> > &distancias, int n, int m, int k);
void busquedaLocal(vector<int> &estado, vector<Estacion> &estaciones, vector<vector<double>> &distancias, bool encontreSolucion );