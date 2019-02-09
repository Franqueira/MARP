#include <iostream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
using namespace std;
int calculaDiferencia(PriorityQueue<int> &rivales, PriorityQueue<int,greater<int>> &broncos) {
	int suma = 0;
	bool seguir = true;
	while (seguir && !rivales.empty()) {
		int v1 = broncos.top();
		int v2 = rivales.top();
		if (v1 <= v2)seguir = false;
		else {
			suma += v1 - v2;
			broncos.pop();
			rivales.pop();
		}
	}
	return suma;
}
bool resuelveCaso() {
	int n, valor;
	cin >> n;
	if (n == 0)return false;
	PriorityQueue<int> rivales;
	PriorityQueue<int,greater<int>> broncos;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		rivales.push(valor);
	}
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		broncos.push(valor);
	}
	cout << calculaDiferencia(rivales, broncos) << '\n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}