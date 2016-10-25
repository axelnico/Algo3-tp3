#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm> //Sort esta en O(n*Log n) y reverse en O(n)
#include "Estacion.h"


std::tuple<int, int, std::vector<int> > solverEj2(std::vector<Estacion> &estaciones, std::vector<std::vector<int> > &distancias, int n, int m, int k);
void greedy_capturar_gimnasios(std::vector<Estacion> &estaciones, std::vector< std::vector<int> > &distancias, int n, int m, int k, std::vector<Estacion> &visitados, int potasActuales, int id_estacion_actual, std::tuple<int,int,std::vector<int> > &soluciones);
void ordenar(std::vector<Estacion> &estaciones, std::vector< std::vector<int> > distancias, int id_estacion_actual);
int id_mas_cercano_que_no_viste(std::vector<int> &distancias, std::vector<int> &vistos, std::vector<Estacion> &estaciones);
void swap(int id_mas_cercano, int i, std::vector<Estacion> &estaciones);
int indice_estacion_con_id(int id, std::vector<Estacion> &estaciones);
int donde_voy(std::vector<Estacion> estaciones, int potasActuales, int k);
bool esta(std::vector<int> &vistos, int j);
