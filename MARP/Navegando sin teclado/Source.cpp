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
	par(int c, int v):clave(c),valor(v) {}
	bool operator<(const par & other) {
		return valor>other.valor;
	}
	bool operator==(const par & other) {
		return valor==other.valor && clave ==other.clave;
	}
};
int tiempoMin(GrafoDirigidoValorado<int> &g) {
	int s = 0;
	vector<AristaDirigida<int>> edgeTo(g.V());
	vector<int> distTo(g.V(),100000000);
	vector<par> pq;
	distTo[0] = 0;
	par p(s,0);
	pq.push_back(p);

	while (!pq.empty())
	{
		par v = pq[pq.size()-1];
		pq.pop_back();
		for (AristaDirigida<int> e : g.ady(v.clave)) {
			int v = e.from();
			int w = e.to();
			par g(w, distTo[w]);
			if (distTo[w] > distTo[v] + e.valor()) {
				distTo[w] = distTo[v] + e.valor();
				edgeTo[w] = e;
				auto op=lower_bound(pq.begin(), pq.end(), g);
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
	return distTo[g.V() - 1];
}

bool resuelveCaso() {
	int n,v;
	cin >> n;
	if (n == 0)return false;
	GrafoDirigidoValorado<int> g(n);
	vector<int> tiemposCarga;
	for (int i = 0; i < n; ++i) {
		cin >> v;
		tiemposCarga.push_back(v);
	}
	int numAristas,principio,final,tiempo;
	cin >> numAristas;
	for (int i = 0; i < numAristas; ++i) {
		cin >> principio >> final >> tiempo;
		g.ponArista(AristaDirigida<int>(principio-1, final-1, tiempo + tiemposCarga[final-1])); // de esta manera lo único que me quedaría por contar es el tiempo de carga de la pag 1
	}
	int sol = tiempoMin(g);
	if (sol ==100000000) {
		cout << "IMPOSIBLE\n";
	}
	else
		cout << sol + tiemposCarga[0] << '\n';

	return true;

}

int main() {
	while(resuelveCaso()){}
}