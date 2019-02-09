#include <iostream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
using namespace std;
int calculaDiferencia(PriorityQueue<int> &esquiadores, PriorityQueue<int> &esquis) {
	int suma = 0;
	while (!esquiadores.empty()) {
		suma += abs(esquiadores.top() - esquis.top());
		esquiadores.pop();
		esquis.pop();
	}

	return suma;
}
bool resuelveCaso() {
	int n,valor;
	cin >> n;
	if (n == 0)return false;
	PriorityQueue<int> esquiadores, esquis;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		esquiadores.push(valor);
	}
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		esquis.push(valor);
	}
	cout << calculaDiferencia(esquiadores, esquis) << '\n';
	return true;
}
int main() {
	while(resuelveCaso()){}
}