#include <iostream>
#include "bintree_eda.h"
using namespace std;

bool estaEquilibrado(bintree<char>arbol, int &altura) {
	if (arbol.empty()) {
		altura = 0;
		return true;
	}
	bool estaEqIz, estaEqDer;
	int alturaIz, alturaDer;
	estaEqIz=estaEquilibrado(arbol.left(), alturaIz);
	estaEqDer = estaEquilibrado(arbol.right(), alturaDer);
	altura = max(alturaIz, alturaDer) + 1;
	return estaEqIz && estaEqDer && abs(alturaIz - alturaDer) <= 1;

}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	bool sol;
	int alt;
	sol = estaEquilibrado(arbol, alt);
	if (sol) cout << "SI\n";
	else cout << "NO\n";

}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();

}