#include <iostream>
#include "Grafo.h"
using namespace std;
// rojoazul true si hay que colorearlo rojo y false si hay que colorearlo azul
bool colorea(Grafo &g, int n, vector<bool> &rojos,vector<bool>& azules,bool rojoazul) {
	if (rojoazul) {
		if (azules[n])
			return false;
		else if (!rojos[n]) {
			bool sol = true;
			rojos[n] = true;
			vector<int> ady = g.ady(n);
			for (int i = 0; i < ady.size() && sol; ++i) {
				sol = sol && colorea(g, ady[i], rojos, azules, false);
			}
			return sol;
		}
		return true;
	}
	else {
		if (rojos[n])
			return false;
		else if(!azules[n]){
			bool sol = true;
			azules[n] = true;
			vector<int> ady = g.ady(n);
			for (int i = 0; i < ady.size() && sol; ++i) {
				sol= sol && colorea(g, ady[i], rojos, azules, true);
			}
			return sol;
		}
		return true;
	}
}
bool resuelveCaso() {
	int N, M, A, B, numUsados = 0;
	cin >> N >> M;
	if (!cin)return false;
	Grafo g(N);

	vector<int> ady;
	vector<bool> azules,rojos;
	for (int i = 0; i < N; ++i) {
		azules.push_back(false);
		rojos.push_back(false);
	}
	int numAmigosMax = 0, numAmigos;
	for (int i = 0; i < M; ++i) {
		cin >> A >> B;
		g.ponArista(A , B);
	}
	int j = 0;
	bool sol = true;
	while (j < N && sol) {
		sol= sol && colorea(g, j, rojos, azules, true);
		j++;
		while (j<N && (rojos[j] || azules[j]))
			j++;
	}
	if (sol)cout << "SI\n";
	else cout << "NO\n";
	return true;
}
int main() {
	while (resuelveCaso()) {}
}