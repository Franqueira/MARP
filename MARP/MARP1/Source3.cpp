#include <iostream>
#include "TreeMap_AVL.h"
using namespace std;

bool resuelveCaso() {
	int tam;
	cin >> tam;
	if (tam == 0)return false;
	map<int, int> arbol;
	int clave;
	for (int i = 0; i < tam; ++i) {
		cin >> clave;
		arbol.insert(map<int,int>::clave_valor(clave));
	}
	int tamk,k;
	cin >> tamk;
	for (int i = 0; i < tamk; ++i) {
		cin >> k;
		if (k > arbol.size())cout << "??\n";
		else {
			int kesimo = arbol.Kesimo(k);
			cout << kesimo << '\n';
		}
	}
	cout << "----\n";
	return true;
}
int main() {
	while (resuelveCaso()) {}

}