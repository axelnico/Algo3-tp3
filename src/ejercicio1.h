#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm> //Sort esta en O(n*Log n) y reverse en O(n)
#include "Estacion.h"


std::tuple<int, int, std::vector<int> > solverEj1(std::vector<Estacion> &estaciones, const std::vector<std::vector<int> > &distancias, int n, int m, int k);
void BT_capturar_gimnasios(std::vector<Estacion> estaciones, const std::vector<std::vector<int> > &distancias, int n, int m, int k, std::vector<Estacion> &visitados, int potasActuales, std::tuple<int,int,std::vector<int> > &soluciones);
bool tiene_solucion(std::vector<Estacion> &estaciones, int k);
bool puede_ganar_gimnasio(Estacion &estacion,int potas);
bool puede_recibir_potas(Estacion &estacion,int potas,int tamano_mochila);
bool es_solucion(std::vector<Estacion> &estaciones);
int distancia_acumulada(std::vector<Estacion> &visitados, const std::vector<std::vector<int> > &distancias);