#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct datos {
	int prof, cant;
	bool cogido;
};
bool resuelveCaso() {
	int T, N,profundidad,cantidad;
	int solucion;
	cin >> T >> N;
	if (!cin)return false;
	vector<vector<int>> cofres(N+1,vector<int>(T+1)); // creo una matriz N+1*T+1
	vector<datos> v;
	for (int i = 0; i < N; ++i) {
		cin >> profundidad >> cantidad;
		v.push_back({ 3*profundidad,cantidad ,false}); //guardo automaticamente 3 veces la profundidad(lo que se tarda en bajar y subir)
	}
	//inicializacion
	for (int j = 0; j < T + 1; ++j) {
		cofres[0][j] = 0;
	}
	for (int i = 0; i < N+1; ++i) {
		cofres[i][0] = 0;
	}
	//funcion
	for (int i = 1; i < N+1; ++i) {
		for (int j = 1; j < T+1; ++j) {
			if (v[i-1].prof > j) {
				cofres[i][j] = cofres[i - 1][j];
			}
			else {
				cofres[i][j] = max(cofres[i - 1][j], cofres[i-1][j - v[i-1].prof] + v[i-1].cant);
			}
		}
	}
	int j = T;
	int numCofres=0;
	//no me valen cofres repetidos así que tengo que ver a ver que puedo hacer
	for (int i = N; i >0 ; --i) {
		if (cofres[i][j] != cofres[i - 1][j]) { // si he cogido el objeto i
			v[i-1].cogido = true;
			j -= v[i-1].prof;
			numCofres++;
		}
	}

	cout << cofres[N][T]<< '\n' << numCofres << '\n';
	for (int i = 0; i < N; ++i) {
		if (v[i].cogido)cout << v[i].prof / 3 << ' ' << v[i].cant << '\n';
	}

	cout << "----\n";

	return true;
}
int main() {
	while (resuelveCaso()) {}
}