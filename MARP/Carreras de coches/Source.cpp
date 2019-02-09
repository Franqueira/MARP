#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int numCoches(vector<int> &coches,int &V) {
	int sol = 0;
	int i = 0;
	int j = coches.size() - 1;
	while (i < j) {
		int pilaValorMax = coches[j];
		while (i<j && coches[i] + pilaValorMax < V) {
			i++;
		}
		if (i < j) {
			sol++;
			++i;
			j--;
		}

	}
	return sol;

}
void resuelveCaso() {
	int valor;
	vector<int> coches;
	int N, V;
	cin >> N >> V;
	for (int i = 0; i < N; ++i) {
		cin >> valor;
		coches.push_back(valor);
	}
	sort(coches.begin(), coches.end());
	//ya tengo el vector ordenado
	cout << numCoches(coches, V) << '\n';

}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}