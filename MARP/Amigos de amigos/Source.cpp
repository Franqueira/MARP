#include <iostream>
#include "Grafo.h"
using namespace std;
int numAmigo(Grafo &g, int n,vector<bool> &usados) {
	if (usados[n]) {
		return 0;
	}
	else {
		usados[n] = true;
		int num = 1;
		vector<int> ady=g.ady(n);
		for (int i = 0; i < ady.size(); ++i) {
			num += numAmigo(g,ady[i],usados);
		}
		return num;
	}
}
void resuelveCaso() {
	int N, M,A,B,numUsados=0;
	cin >> N >> M;
	Grafo g(N);

	vector<int> ady;
	vector<bool> usados;
	for (int i = 0; i < N; ++i) {
		usados.push_back(false);
	}
	int numAmigosMax=0,numAmigos;
	for (int i = 0; i < M; ++i) {
		cin >> A >> B;
		g.ponArista(A - 1, B - 1);
	}
	int j = 0;
	while (j < N) {
		numAmigos=numAmigo(g, j, usados);
		if (numAmigos > numAmigosMax)
			numAmigosMax = numAmigos;
		j++;
		while (j<N && usados[j])
			j++;
	}
	cout << numAmigosMax << '\n';
	
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}