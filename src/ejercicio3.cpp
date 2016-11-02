#include "ejercicio3.h"

tuple<double, int, vector<int> > solverEj3(vector<Estacion> estaciones, vector<vector<double> > &distancias, int n, int m, int k){
	
	vector<Estacion> estacionesAuxiliar = estaciones;
	tuple<double, int, vector<int> > primerEstado = solverEj2(estaciones, distancias, n, m, k); //Primer candidato a solucion
	imprimirEstado(primerEstado);

	double distanciaInicial = get<0>(primerEstado); //Copio la distancia

	if (distanciaInicial != -1) {
		
		vector<int> recorridoInicial = get<2>(primerEstado); //Copio el recorrido del candidato a solucion
		int cantVertices = get<1>(primerEstado);
	
		primerEstado = busquedaLocal(recorridoInicial, estacionesAuxiliar, distancias, distanciaInicial, cantVertices);
		 
	}

	imprimirEstado(primerEstado);

	return primerEstado;
}

void imprimirEstado(tuple<double, int, vector<int> > primerEstado)
{
	cout<< endl;
	cout << "Distancia: " << get<0>(primerEstado) << " CantVert:" << get<1>(primerEstado) << endl;
	cout << " recorrido ";
	for (int i = 0; i < get<1>(primerEstado); ++i){
		cout << get<2>(primerEstado)[i] << " ";
	}
	cout << endl; 
}

// tuple<double, int, vector<int>> 
tuple<double, int, vector<int> > busquedaLocal(vector<int> recorrido, const vector<Estacion> estaciones, vector<vector<double>> &distancias, double distancia, const int cantVertices){
	vector<vector<int>> vecindario;

	bool noHayMasSoluciones = false;
	double distanciaMinima;
	double distanciaAux;
	int proximoEstado;

	while (!noHayMasSoluciones) {

		vecindario = dameVecindario(estaciones, recorrido);
		proximoEstado = -1;

    	if (vecindario.size() > 0) {
			
			distanciaMinima = distancia;
			
			//Busco algun vecino con distancia mas chica
			for (uint i = 0; i < vecindario.size(); ++i) {
				
				distanciaAux = dameDistancia(vecindario[i], distancias);
				if (distanciaAux < distanciaMinima) {
					distanciaMinima = distanciaAux;
					proximoEstado = i;
				}
			}
    	}
	
		if (proximoEstado > -1) {
			recorrido = vecindario[proximoEstado];
			distancia = distanciaMinima;
    	}
    	else {
    		noHayMasSoluciones = true;
    	}
	}

	return make_tuple(distancia, cantVertices, recorrido);
}


double dameDistancia(const vector<int> recorrido, const vector<vector<double>> distancias){
	double distancia = 0;
	for (uint i = 0; i < recorrido.size() - 1; i++) {
		distancia += distancias[recorrido[i]][recorrido[i + 1]];
	}
	return distancia;
}


vector<vector<int>>  dameVecindario (const vector<Estacion> estaciones, const vector<int> recorrido){
	vector<vector<int>> vecindario;

	for (uint i = 0; i < recorrido.size() - 1; ++i) {
		if (!estaciones[recorrido[i]].esGimnasio) {
			for (uint j = i+1; j < recorrido.size(); j++) {
				if (!estaciones[recorrido[j]].esGimnasio) {
					vector<int> estadoAux = recorrido;
					swap(estadoAux, i, j);
					vecindario.push_back(estadoAux);
				}
			}
		}
	}

	return vecindario;
}




void swap(vector<int> &estado, int i, int j){
	int x = estado[j];
	estado[j] = estado[i];
	estado[i] = x;
}