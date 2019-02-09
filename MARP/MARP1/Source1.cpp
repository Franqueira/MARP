#include <iostream>
#include "bintree_eda.h"
using namespace std;

bool esAVL(bintree<int>arbol, int &altura,int &minimo,int &maximo) {
	if (arbol.empty()) {
		altura = 0;
		minimo = 2147483647;
		maximo = -1;
		return true;
	}
	bool esAVLIz, esAVLDer;
	int alturaIz, alturaDer,minimoIz,minimoDer,maximoIz,maximoDer;
	esAVLIz = esAVL(arbol.left(), alturaIz,minimoIz,maximoIz);
	esAVLDer = esAVL(arbol.right(), alturaDer,minimoDer,maximoDer);
	altura = max(alturaIz, alturaDer) + 1;
	minimo = min(minimoIz,arbol.root()); //por si es vacío el hijo
	maximo = max(maximoDer,arbol.root());//por si es vacío el hijo
	return esAVLIz && esAVLDer && abs(alturaIz - alturaDer) <= 1 && maximoIz<arbol.root() && minimoDer>arbol.root();
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	bool sol;
	int alt,minimo,maximo;
	sol = esAVL(arbol, alt,minimo,maximo);
	if (sol) cout << "SI\n";
	else cout << "NO\n";

}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();

}