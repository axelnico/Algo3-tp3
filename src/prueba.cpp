#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <fstream>
#include <utility>
#include <vector>
#include <tuple>
#include <list>
#include <string>
#include <set>


using namespace std;

//g++ -g -std=c++11 prueba.cpp -o prueba


void swap(vector<int> &estado, int i, int j){
	int x = estado[j];
	estado[j] = estado[i];
	estado[i] = x;
}	



void dame_perm(vector<int> a ){
	
	
	bool algunoDistinto = true;
	vector<vector<int>> vecinosAux;
	set<vector<int>> vecindario;
	
	int keke = 0;
	bool aux;
	int marmota = 0;
	while(marmota < 5){
		for (int h = 0; h < a.size(); ++h)
		{
			cout << a[h] << " , ";
		}
		cout << endl;
		cout << endl;
		for(int i = 0; i < a.size() - 1; i++) {
			for (int j = i + 1; j < a.size(); j++) {
				vector<int> estadoAux = a;
				swap(estadoAux, i,j);

				cout << endl;
				vecinosAux.push_back(estadoAux);
			}
		}
		if (keke == 0){
			for (int k = 0; k < vecinosAux.size(); ++k)
			{
				vecindario.insert(vecinosAux[k]);

				for (int n = 0; n < vecinosAux[k].size(); ++n)
				{
					cout << vecinosAux[k][n] << " ";
				}
				cout << endl;
				a = vecinosAux[0];
			}
		} else {
			for (int k = 0; k < vecinosAux.size(); ++k)
			{
				aux = vecindario.count(vecinosAux[k]) == 0;

				if(aux){
					algunoDistinto = algunoDistinto && aux;
					a = vecinosAux[k];
				}
				vecindario.insert(vecinosAux[k]);
			}
		}

		keke++;
		marmota++;

	}
}

// vector<vector<int>> dameVecindario (vector<tuple<int, bool>> estaciones, vector<int> estado){
// 	vector<vector<int>> vecindario; 
// 	for (uint i = 0; i < estado.size() - 1; ++i) {
// 		if(!get<1>(estaciones[estado[i] - 1])) { 
// 			for (uint j = i+1; j < estado.size(); j++) {
// 				if (!get<1>(estaciones[estado[j] - 1])){
// 					vector<int> estadoAux = estado;
// 					swap(estadoAux, i, j);
// 					vecindario.push_back(estadoAux);
// 				}
// 			}
// 		}

// 	}

// 	return vecindario;
// }


int main()
{
	vector<int> a = {1,2,3,4};
	dame_perm(a);
}

//(4,T)(2,F)(3,T)(1,T)