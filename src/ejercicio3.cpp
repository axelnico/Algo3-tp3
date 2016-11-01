#include "ejercicio3.h"

tuple<double, int, vector<int> > solverEj3(vector<Estacion> &estaciones, vector<vector<double> > &distancias, int n, int m, int k){
	vector<Estacion> estacionesAuxiliar;
	for (Estacion estacion : estaciones)	{
		Estacion estacionAux = estacion;
		estacionesAuxiliar.push_back(estacionAux);
	}
	tuple<double, int, vector<int> >  primerEstado = solverEj2(estaciones, distancias, n, m, k);
	
	vector<int> recorridoInicial = get<2>(primerEstado);

	int distanciaInicial = get<0>(primerEstado);
	busquedaLocal(estadoInicial, estacionesAuxiliar, distancias, false, distanciaInicial);
	
}


// void busquedaLocal(vector<int> &estado, vector<Estacion> &estaciones, vector<vector<double>> &distancias, bool encontreSolucion, int distanciaInicial){
// 	if (!encontreSolucion){
// 		for (int i = 0; i < estado.size(); ++i)
// 		{
// 			/* code */
// 		}
// 	}
// }


// p1,2,p3,p4

// (p3,2,p1,p4),(p4, 2, p3, p1), (p1, 2, p4, p3)


// (p4, 2, p1, p3), (P3, 2 , )
