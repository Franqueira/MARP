#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include"ConjuntosDisjuntos.h"
using namespace std;
struct valores {
	int A;
	int B;
	int coste;
	bool operator<(const valores & other) {
		return coste<other.coste;
	}
};

bool resuelveCaso() {
	int V, E, A, B, coste;
	cin >> V >> E;
	ConjuntosDisjuntos c(V);
	vector<valores> ordenados;
	if (!cin)return false;
	valores v;
	for (int i = 0; i < E; ++i) {
		cin >> A >> B >> coste;
		v.A = A-1;
		v.B = B-1;
		v.coste = coste;
		ordenados.insert(lower_bound(ordenados.begin(), ordenados.end(), v), v);
	}
	int costeAcumulado = 0;
	for (valores v : ordenados) {
		if (!c.unidos(v.A, v.B)) { // si no formo ciclo
			costeAcumulado += v.coste;
			c.unir(v.A, v.B);
		}
	}
	if (c.num_cjtos() > 1) {
		cout << "No hay puentes suficientes\n";
	}
	else cout << costeAcumulado << '\n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}