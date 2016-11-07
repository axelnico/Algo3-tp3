#include "ejercicio4.h"

tuple<double, int, vector<int> > solverEj4(vector<Estacion> estaciones, vector<vector<double> > &distancias, int n, int m, int k, int grasp) {
	vector<int> posiblesProximo;
	int proximo;
	vector<int> camino_nulo;

	vector<int> recorrido;
	vector<Estacion> estacionesAuxiliar = estaciones;
	int ultimoID = -1;
	double distancia = 0;

	while (!estacionesAuxiliar.empty()) { //O(n) siendo n la cantidad de estaciones

		//Obtengo todos los posibles próximos nodos a recorrer
		posiblesProximo.clear(); 
		for (Estacion estacion : estacionesAuxiliar) { //O(n) pero no se multiplica por el n del while. Se suma porque va disminuyendo el n
			if (puedoMeter(estaciones, recorrido, estacion, k)) { //O(n)
				posiblesProximo.push_back(estacion.id);
			}
		}

		if (posiblesProximo.empty())
			 return make_tuple(-1, -1, camino_nulo);

		//Ordeno esos nodos por costo ascendente
		if (ultimoID > -1)
			ordenarPorCosto(posiblesProximo, distancias[ultimoID]); //O(n log n)

		//Me quedo con los grasp nodos mas baratos
		if (grasp < posiblesProximo.size())
			posiblesProximo.resize(grasp);

		//Elijo al azar uno de esos nodos y lo agrego a mi recorrido
		proximo = posiblesProximo[random(grasp)];
		recorrido.push_back(proximo);

		if (ultimoID > -1)
			distancia += distancias[ultimoID][proximo];
			
		ultimoID = proximo;

		estacionesAuxiliar.erase(estacionesAuxiliar.begin() + proximo);

		//Si no me quedan gimnasios por conquistar, gané
		if (sonTodosPotas(estacionesAuxiliar)) //O(n) pero no se multiplica por el n del while. Se suma porque va disminuyendo el n
			break;
	}

	return make_tuple(distancia, recorrido.size(), recorrido);
}

bool puedoMeter(const vector<Estacion>& estaciones, const vector<int>& recorrido, const Estacion& nuevaEstacion, const int k) {
	if (!nuevaEstacion.esGimnasio)
		return true;

	int pociones = 0;

	for (int r : recorrido) { //O(n)
		if (!estaciones[r].esGimnasio) {
			pociones = min(pociones + 3, k);
		}
		else {
			pociones -= estaciones[r].potas;
		}
	}

	return (-nuevaEstacion.potas) <= pociones;
}

void ordenarPorCosto(vector<int>& lista, const vector<double>& distancias)
{
	vector< pair<int, double> > toSort;
	for (int item : lista)
	{
		toSort.push_back({item, distancias[item]});
	}
	//sort by second

	sort(toSort.begin(), toSort.end(), pairCompare);

	lista.clear();
	for (pair<int, double> item : toSort)
	{
		lista.push_back(item.first);
	}
}

bool sonTodosPotas(const vector<Estacion> & estaciones) {
	for (Estacion estacion : estaciones)
	{
		if (estacion.esGimnasio) {
			return false;
		}
	}
	return true;
}

int random(int limit) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> tam(0, limit - 1);
	return tam(gen);
}

bool pairCompare(const pair<int, double>& firstElem, const pair<int, double>& secondElem) {
  return firstElem.second < secondElem.second;
}