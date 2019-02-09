#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct datos {
	int numManeras, numMin, minCoste;
};
bool resuelveCaso() {
	int N, L, longitud, coste;
	cin >> N >> L;
	vector<datos> valoresAcumulados;
	if (!cin)return false;
	cin >> longitud >> coste;
	//inicializacion de los vectores de datos
	valoresAcumulados.push_back({ 1,0,0 });
	for (int i =1; i <L+1; ++i) { // cada i representa la longitud de la varilla.
		if (longitud == i) { // la varilla llega
			valoresAcumulados.push_back({ 1,1,coste });
		}
		else { //la varilla no llega para cubrir una longitud i
			valoresAcumulados.push_back({ 0,0,0 });
		}
	}
	for (int i = 1; i < N; ++i) {
		cin >> longitud >> coste;
		for (int j = L; j >= 0; --j) {
			if (longitud <= j && valoresAcumulados[j-longitud].numManeras>0) { // es decir no hay opcion a que las varillas anteriores te permitiesen hacer una nueva varilla
				if (valoresAcumulados[j].numManeras > 0) {
					valoresAcumulados[j].numManeras += valoresAcumulados[j - longitud].numManeras;
					valoresAcumulados[j].minCoste = min((valoresAcumulados[j - longitud].minCoste + coste), valoresAcumulados[j].minCoste);
					valoresAcumulados[j].numMin = min(valoresAcumulados[j - longitud].numMin + 1, valoresAcumulados[j].numMin);

				}
				else { // si no la hay
					valoresAcumulados[j].numManeras = valoresAcumulados[j - longitud].numManeras;
					valoresAcumulados[j].minCoste = valoresAcumulados[j - longitud].minCoste + coste;
					valoresAcumulados[j].numMin = valoresAcumulados[j - longitud].numMin + 1;
				}
			}
		}
				
	}
	if (valoresAcumulados[L].numManeras > 0)cout << "SI " << valoresAcumulados[L].numManeras << ' ' << valoresAcumulados[L].numMin << ' ' << valoresAcumulados[L].minCoste << '\n';
	else cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso()) {}

}

