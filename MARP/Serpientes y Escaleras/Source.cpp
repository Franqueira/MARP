#include <iostream>
#include <vector>
#include "GrafoDirigido.h"
#include <climits>
using namespace std;
int casillasHastaFinal(GrafoDirigido &grafo, int casilla,int numMov,int &k, vector <pair<bool, int>> &v,int &N) {
	if (numMov > v[casilla].second) { // en otro caso el camino puede ser factible.
		return INT_MAX;
	}else{
		v[casilla].second = numMov;
		int ultimaCasilla = N * N - 1;
		int ProxCasilla, mejorNumMov = INT_MAX;
		int posibleNumMov;
		int mejorI = -1;
		for (int i = 1; i <= k; ++i) { // recorro las próximas casillas
			ProxCasilla = casilla + i;
			v[ProxCasilla].first = true;
			if (ProxCasilla >= ultimaCasilla)
				return numMov + 1;
			if (v[ProxCasilla].second == INT_MAX || numMov + 1 < v[ProxCasilla].second) {
				v[ProxCasilla].second = numMov + 1;
				vector<int> adyac = grafo.ady(ProxCasilla);
				if (!adyac.empty()) { // hay escalera o serpiente, por lo que tengo que explorar lo que pasa en esas situaciones
					for (int i = 0; i < adyac.size(); ++i) {
						posibleNumMov = casillasHastaFinal(grafo, adyac[i], numMov + 1, k, v, N);
						if (posibleNumMov < mejorNumMov)
							mejorNumMov = posibleNumMov;

					}
				}
				else { //es una escalera sin otras asociadas.
					mejorI = i;
				}
			}
		}
		//exploro el mejor movimiento que no sea mover a escalera o serpiente
		if (mejorI != -1) {
			posibleNumMov = casillasHastaFinal(grafo, casilla + mejorI, numMov + 1, k, v, N);
			if (posibleNumMov < mejorNumMov)
				mejorNumMov = posibleNumMov;
		}
		return mejorNumMov;// devuelvo el mayor entero cuando no es prometedor el camino seguido porque ya hay uno mejor
	}

}
bool resuelveCaso() {
	int N, K, S, E,inicio,fin;
	cin >> N >> K >> S >> E;
	if (N==0 && K==0 && S==0 && E==0)return false;
	GrafoDirigido escalerasyserpientes(N*N);
	vector <pair<bool,int>> v;
	for (int i = 0; i < N*N; ++i) {
		v.push_back(make_pair(false,INT_MAX));
	}
	for (int i = 0; i < S; ++i) {
		cin >> inicio >> fin;
		escalerasyserpientes.ponArista(inicio - 1, fin - 1);
	}
	for (int i = 0; i < E; ++i) {
		cin >> inicio >> fin;
		escalerasyserpientes.ponArista(inicio - 1, fin - 1);
	}
	int sol = casillasHastaFinal(escalerasyserpientes, 0, 0, K, v, N);
	cout << sol << '\n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}