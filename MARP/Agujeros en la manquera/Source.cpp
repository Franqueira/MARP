#include <iostream>
#include <vector>
using namespace std;
vector<int> numPinchazos(vector<int> &pinchazos,int &minutosTurno) {
	int i = 0;
	vector<int> comienzoTurno;
	while (i < pinchazos.size()) {
		comienzoTurno.push_back(pinchazos[i]);
		int v = pinchazos[i];
		while (i<pinchazos.size() && minutosTurno + v >= pinchazos[i]) {
			i++;
		}
	} 
	return comienzoTurno;
}
bool resuelveCaso() {
	int N, L,valor;
	cin >> N >> L;
	vector <int> parches;
	if (!cin)return false;
	for (int i = 0; i < N; ++i) {
		cin >> valor;
		parches.push_back(valor);
	}

	cout << numPinchazos(parches, L) << '\n';

	return true;
}
int main() {
	while(resuelveCaso()){}
}