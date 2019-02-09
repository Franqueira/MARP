#include <iostream>
#include "Matriz.h"
using namespace std;
void rellena(Matriz<bool> &datos, int fila, int columna) {
	if (fila >= 0 && fila < datos.numfils() && columna >= 0 && columna < datos.numcols() && !datos[fila][columna]) {
		datos[fila][columna] = true;
		rellena(datos, fila - 1, columna);
		rellena(datos, fila + 1, columna);
		rellena(datos, fila, columna + 1);
		rellena(datos, fila, columna - 1);
	}
}

bool resuelveCaso() {
	int filas, columnas;
	char valor;
	cin >> columnas >> filas;
	if (!cin)return false;
	Matriz<bool> datos(filas,columnas);
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			cin >> valor;
				datos[i][j] = (valor=='X' ? true:false);
		}
	}
	rellena(datos, 0, 0);
	int numOvejas = 0;
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			if (!datos[i][j]) {
				numOvejas++;
				rellena(datos, i, j);
			}
		}
	}
	cout << numOvejas << '\n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}


/*
void marcaValores(Matriz<char> &datos, vector<vector<bool>> & usados, int fila, int columna) {
bool quedanPorMarcarIz=true, quedanPorMarcarDer = true;
int c= columna;
while (quedanPorMarcarIz) {
if (datos[fila][columna] == '.') {
usados[fila][columna] = true;
columna--;
}
else {
quedanPorMarcarIz = false;
}
}
while (quedanPorMarcarDer) {
if (datos[fila][c+1] == '.') {
usados[fila][c+1] = true;
c++;
}
else {
quedanPorMarcarDer = false;
}
}

}
int numOvejas(Matriz<char> &datos,vector<vector<bool>> & usados ,int &filas,int &columnas) {
int numOvejas=0;
for (int i = 1; i < filas-3; ++i) { // no puedo detectar otra oveja más abajo
for (int j = 1; j < columnas-2; ++j) { // ni mas a la derecha
if (!usados[i][j] && datos[i][j]=='X') {
usados[i][j] = true;
if (!usados[i+1][j] && datos[i + 1][j] == '.' && datos[i + 2][j] == 'X') {
numOvejas++;
marcaValores(datos, usados, i + 1, j);
}
}
}
}
return numOvejas;
}
*/