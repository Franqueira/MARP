#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;
bool resuelveCaso() {
	string A, B;
	cin >> A >> B;
	if (!cin)return false;
	int N, M;
	N = A.length();
	M = B.length();
	vector<int> nCoincidencias(M + 1,0);
	int valorAnteriorFC,aux;
	for (int i = 0; i < N; ++i) {
		valorAnteriorFC = 0;
		for (int j = 1; j < M+1; ++j) {
			if (A[i] == B[j - 1]) {
				aux = max(valorAnteriorFC + 1, max(nCoincidencias[j],nCoincidencias[j-1]));
			}
			else {
				aux = max(valorAnteriorFC, max(nCoincidencias[j], nCoincidencias[j - 1]));
			}
			valorAnteriorFC = nCoincidencias[j];//actualizo el valor(estaría en la esquina izquierda de la matriz)
			nCoincidencias[j] = aux;
		}
	}

	cout << nCoincidencias[M] << '\n';


	return true;
}
int main() {
	while (resuelveCaso()) {}
}