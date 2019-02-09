#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool resuelveCaso() {
	int N,valor;
	cin >> N;
	if (!cin)return false;
	vector<vector<int>> datos(N, vector<int>(N));
	vector<vector<int>> sumasAcumuladas(N, vector<int>(N));
	//proceso la entrada
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> valor;
			datos[i][j] = valor;
		}
	}
	for (int j = 0; j < N; ++j) {
		sumasAcumuladas[0][j] = datos[0][j]; // inicializo mi matriz de sumas acumuladas(podría reutilizar la matriz
	}

	//Voy calculando las sumas máximas de cada fila
	for (int i = 1; i < N; ++i) {
		sumasAcumuladas[i][0] = max(sumasAcumuladas[i - 1][0], sumasAcumuladas[i - 1][1])+datos[i][0]; //puedo hacerlo ya que N>=3
		for (int j = 1; j < N-1; ++j) { //proceso los otros dos casos fuera
			sumasAcumuladas[i][j] = max(sumasAcumuladas[i - 1][j - 1], max(sumasAcumuladas[i - 1][j], sumasAcumuladas[i - 1][j + 1])) + datos[i][j];
		}
		sumasAcumuladas[i][N - 1] = max(sumasAcumuladas[i - 1][N - 1], sumasAcumuladas[i-1][N - 2]) + datos[i][N-1];
	}
	int max = 0;
	for (int j = 1; j < N; ++j) {
		if (sumasAcumuladas[N-1][j] > sumasAcumuladas[N-1][max])max = j;
	}
	cout << sumasAcumuladas[N-1][max] << ' ' << max + 1 << '\n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}