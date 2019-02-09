#include <iostream>
#include "GrafoValorado.h"
using namespace std;
bool HayCamino(GrafoValorado<int> &g, vector<bool> &usados,int origen, int &destino, int &anchoCamion) {
	if (origen == destino)
		return true;
	else {
		bool sol;
		int valor;
		usados[origen] = true;
		vector<Arista<int>> ady = g.ady(origen);
		for (int i = 0; i < ady.size(); ++i) {
			valor = ady[i].otro(origen);
			if (!usados[valor] && ady[i].valor() >= anchoCamion) {
				sol = HayCamino(g, usados, valor, destino, anchoCamion);
				if (sol) {
					return true;
				}
			}
		}
		return false;
	}

}
bool resuelveCaso() {
	int V, E,A,B,ancho;
	cin >> V >> E;
	if (!cin)return false;
	GrafoValorado<int> g(V);
	for (int i = 0; i < E; ++i) {
		cin >> A >> B>>ancho;
		g.ponArista(Arista<int>(A-1, B-1, ancho));
	}
	int K,origen,destino,anchoCamion;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> origen >> destino >> anchoCamion;
		destino -= 1;
		vector<bool> usados(V, false);
		if (HayCamino(g, usados,origen-1, destino, anchoCamion)) 
			cout << "SI\n";
		else
			cout << "NO\n";
	}

	return true;
}
int main() {
	while (resuelveCaso()) {}
}