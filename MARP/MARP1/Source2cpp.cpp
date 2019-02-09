#include <iostream>
#include <vector>
#include "TreeMap_AVL.h"
#include "bintree_eda.h"
#include <list>
using namespace std;

bintree<int> insert(bintree<int> arbol, int &valor) {
	if (arbol.empty()) {
		return(bintree<int>(valor));
	}
	else if (valor < arbol.root()) {
			return(bintree<int>( insert(arbol.left(),valor),arbol.root(),arbol.right() ));
	}
	else 
		return (bintree<int>(arbol.left(),arbol.root(),insert(arbol.right(), valor)));
}
void listaR(bintree<int> arbol, int &k1,int&k2,  vector<int>& resultado) {
	if (!arbol.empty()) {
		if (arbol.root()>=k1 && arbol.root()<=k2) {
			listaR(arbol.left(), k1, k2, resultado);
			resultado.push_back(arbol.root());
			listaR(arbol.right(), k1, k2, resultado);
		}
		else if (arbol.root() < k1) listaR(arbol.right(), k1, k2, resultado);
		else listaR(arbol.left(), k1, k2, resultado);
	}
}
void hacerArbolLog(vector<int> &ordenado, bintree<int> &arbol,int principio,int final) {
	if (principio <= final) {
		int medio = (principio + final) / 2;
		arbol = insert(arbol, ordenado[medio]);
		hacerArbolLog(ordenado, arbol, principio, medio - 1);
		hacerArbolLog(ordenado, arbol, medio+1, final);
	}
}
bool resuelveCaso() {
	int tam,valor;
	int k1, k2;
	vector<int> resultado;
	vector<int> amarbol;
	cin >> tam;
	if (tam == 0)return false;
	bintree <int> arbol;
	cin >> valor;
	amarbol.push_back(valor);
	for (int i = 1; i < tam; ++i) {
		cin >> valor;
		//inserto ordenadamente
		amarbol.insert(lower_bound(amarbol.begin(), amarbol.end(), valor), valor);
		//arbol=insert(arbol,valor);
	}
	hacerArbolLog(amarbol, arbol, 0, amarbol.size()-1);
	cin >> k1 >> k2;
	listaR(arbol, k1, k2, resultado);
	if (resultado.empty()) cout << '\n';
	else {
		for (int i = 0; i < resultado.size()-1; ++i) {
			cout << resultado[i] << ' ';
		}
		cout <<resultado[resultado.size() - 1] << '\n';
	}
	return true;
}
int main() {
	while (resuelveCaso()) {}
}