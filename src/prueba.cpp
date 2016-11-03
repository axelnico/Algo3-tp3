#include <prueba.h>

using namespace std;

void swap(vector<int> &estado, int i, int j){
	int x = estado[j];
	estado[j] = estado[i];
	estado[i] = x;
}	

vector<vector<int>> dameVecindario (vector<tuple<int, bool>> estaciones, vector<int> estado){
	vector<vector<int>> vecindario; 
	for (uint i = 0; i < estado.size() - 1; ++i) {
		if(!get<1>(estaciones[estado[i] - 1])) { 
			for (uint j = i+1; j < estado.size(); j++) {
				if (!get<1>(estaciones[estado[j] - 1])){
					vector<int> estadoAux = estado;
					swap(estadoAux, i, j);
					vecindario.push_back(estadoAux);
				}
			}
		}

	}

	return vecindario;
}


int main()
{

}

//(4,T)(2,F)(3,T)(1,T)