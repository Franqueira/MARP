#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Matriz.h"
#include "ConjuntosDisjuntos.h"
using namespace std;
void junta(Matriz<bool> &datos, ConjuntosDisjuntos &conjunto, int fila, int columna, int &manchaGrande, bool todasLasDirecciones) { //junto solo las manchas 
	if (datos[fila][columna]) {
		int dato = datos.numcols()*fila + columna;
		if (fila > 0 && datos[fila - 1][columna]) { //casilla de la arriba
			conjunto.unir(dato, datos.numcols()*(fila - 1) + columna);
		}
		if (columna > 0 && datos[fila][columna - 1]) { // casilla de la izquierda
			conjunto.unir(dato, datos.numcols()*fila + (columna - 1));
		}
		if (fila > 0 && columna > 0 && datos[fila - 1][columna - 1]) { //esquina de arriba izquierda
			conjunto.unir(dato, datos.numcols()*(fila - 1) + (columna - 1));
		}
		if (fila > 0 && columna < (datos.numcols() - 1) && datos[fila - 1][columna + 1]){ //esquina de arriba derecha
			conjunto.unir(dato, datos.numcols()*(fila - 1) + (columna + 1));
		}
		if (todasLasDirecciones) {
			if (fila < (datos.numfils() - 1) && datos[fila+1][columna] ) { //abajo
				conjunto.unir(dato, datos.numcols()*(fila + 1)+columna);
			}
			if (columna < (datos.numcols() - 1) && datos[fila][columna + 1]) { // derecha
				conjunto.unir(dato, datos.numcols()*fila+(columna + 1));
			}
			if (fila < (datos.numfils() - 1) && columna >0 && datos[fila + 1][columna - 1]) { //esquina de abajo izquierda
				conjunto.unir(dato, datos.numcols()*(fila + 1) + (columna - 1));
			}
			if (fila < (datos.numfils() - 1) && columna < (datos.numcols() - 1) && datos[fila + 1][columna + 1]) { //esquina de abajo a la derecha
				conjunto.unir(dato, datos.numcols()*(fila + 1) + (columna + 1));
			}
		}
		manchaGrande = max(manchaGrande, conjunto.tam(datos.numcols()*fila+columna));
	}
}

bool resuelveCaso() {
	int filas, columnas;
	char valor;
	int manchaGrande=0;
	cin >> filas >> columnas;
	if (!cin)return false;
	Matriz<bool> datos(filas, columnas); // se podría usar una matriz de booleanos ya que solo toman dos valores
	ConjuntosDisjuntos conjunto(filas*columnas);
	cin.get(valor);
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			cin.get(valor);
			datos[i][j] = (valor == '#' ? true : false);
			junta(datos,conjunto, i, j,manchaGrande,false);
		}
		cin.get(valor);
	}
	cout << manchaGrande;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> filas >> columnas;
		datos[filas - 1][columnas - 1] = true;
		junta(datos, conjunto, filas - 1, columnas - 1, manchaGrande, true);
		cout << ' ' << manchaGrande;
	}
	cout << '\n';

	return true;
}
int main() {
	while (resuelveCaso()) {}

}