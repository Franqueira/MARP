#include <iostream>
#include "PriorityQueue.h"
using namespace std;
bool resuelveCaso() {
	int tam;
	int v;
	PriorityQueue<long long> cola;
	cin >> tam;
	if (tam == 0)return false;
	for (int i = 0; i < tam; ++i) {
		cin >> v;
		cola.push(v);
	}
	long long suma=0,v1,v2;
	while (cola.size()>1) {
		v1 = cola.top();
		cola.pop();
		v2 = cola.top();
		cola.pop();
		cola.push(v1 + v2);
		suma += v1 + v2;
	}
	cout << suma << '\n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}