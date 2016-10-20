#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm> //Sort esta en O(n*Log n) y reverse en O(n)
#include "Estacion.h"


tuple<int, int, vector<int> > solverEj1(std::vector<Estacion> &estaciones, int n, int m, int k);
tuple<int, int, vector<int> > BT_capturar_gimnasios(std::vector<Estacion> &estaciones, int n, int m, int k, std::vector<Estacion> &visitados, std::tuple<int,int,std::vector<int> > soluciones);
bool tiene_solucion(std::vector<Estacion> &estaciones);
bool es_solucion(std::vector<Estacion> &estaciones);
