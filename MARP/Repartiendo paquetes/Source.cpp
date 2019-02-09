#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "GrafoDirigidoValorado.h"
using namespace std;
//quiero que los de valor más bajo estén al final para así poder borrar más eficientemente
struct par {
	int clave;
	int valor;
	par(int c, int v) :clave(c), valor(v) {}
	bool operator<(const par & other) {
		return valor>other.valor;
	}
	bool operator==(const par & other) {
		return valor == other.valor && clave == other.clave;
	}
};
int tiempoMin(GrafoDirigidoValorado<int> &g,int &s,vector<int> &casas, bool &posible) {
	vector<AristaDirigida<int>> edgeTo(g.V());
	vector<int> distTo(g.V(), 1000000000);
	vector<par> pq;
	distTo[s] = 0;
	par p(s, 0);
	pq.push_back(p);

	while (!pq.empty())
	{
		par v = pq[pq.size() - 1];
		pq.pop_back();
		for (AristaDirigida<int> e : g.ady(v.clave)) {
			int v = e.from();
			int w = e.to();
			par g(w, distTo[w]);
			if (distTo[w] > distTo[v] + e.valor()) {
				distTo[w] = distTo[v] + e.valor();
				edgeTo[w] = e;
				auto op = lower_bound(pq.begin(), pq.end(), g);
				if (op != pq.end()) {
					par &valor = pq[op - pq.begin()];
					if (g == valor) { // si está en el vector
						valor.valor = distTo[w];
					}
					else { // si no está
						pq.insert(op, par(w, distTo[w]));
					}
				}
				else { // si no está
					pq.insert(op, par(w, distTo[w]));
				}
			}
		}
	}
	posible = true;
	int sol = 0;
	for (int i = 0; i < casas.size() && posible; ++i) {
		if (distTo[casas[i]] == 1000000000)
			posible = false;
		sol += distTo[casas[i]];
	}
	return sol;
}

bool resuelveCaso() {
	int V, numAristas;
	cin >> V >> numAristas;
	if (!cin)return false;
	GrafoDirigidoValorado<int> g(V),gRevertido(V);
	int principio, final, tiempo;
	for (int i = 0; i < numAristas; ++i) {
		cin >> principio >> final >> tiempo;
		g.ponArista(AristaDirigida<int>(principio - 1, final - 1, tiempo)); // de esta manera lo único que me quedaría por contar es el tiempo de carga de la pag 1
		gRevertido.ponArista(AristaDirigida<int>(final - 1, principio - 1, tiempo));
	}
	int O, P;
	cin >> O >> P;
	O--;
	int valor;
	vector<int> casas;
	for (int i = 0; i < P; ++i) {
		cin >> valor;
		casas.push_back(valor-1);
	}
	bool posibleg, posiblegInvertido;
	int sol = tiempoMin(g, O, casas,posibleg) + tiempoMin(gRevertido,O,casas,posiblegInvertido);
	if (!posibleg ||!posiblegInvertido)
		cout << "Imposible\n";
	else cout << sol << '\n';
	return true;
}

int main() {
	while (resuelveCaso()) {}
}