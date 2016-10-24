#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm> //Sort esta en O(n*Log n) y reverse en O(n)
#include "Estacion.h"


std::tuple<int, int, std::vector<int> > solverEj2(std::vector<Estacion> &estaciones, std::vector<std::vector<int> > &distancias, int n, int m, int k);
void greedy_capturar_gimnasios(std::vector<Estacion> &estaciones, std::vector< std::vector<int> > &distancias, int n, int m, int k, std::vector<Estacion> &visitados, int potasActuales, int id_estacion_actual, std::tuple<int,int,std::vector<int> > &soluciones);
// bool tiene_solucion(std::vector<Estacion> &estaciones, int k);
// bool puede_ganar_gimnasio(Estacion &estacion,int potas);
// bool puede_recibir_potas(Estacion &estacion,int potas,int tamano_mochila);
// bool es_solucion(std::vector<Estacion> &estaciones);
// int distancia_acumulada(std::vector<Estacion> &visitados, const std::vector<std::vector<int> > &distancias);
void ordenar(std::vector<Estacion> &estaciones, std::vector< std::vector<int> > distancias, int id_estacion_actual);
int id_mas_cercano_que_no_viste(std::vector<int> &distancias);
void swap(int id_mas_cercano, int i, std::vector<Estacion> &estaciones);
int indice_estacion_con_id(int id, std::vector<Estacion> &estaciones);
int donde_voy(std::vector<Estacion> estaciones, int potasActuales, int k);