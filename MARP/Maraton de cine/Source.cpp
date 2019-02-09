#include <iostream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct horas {
	int inicio;
	int final;
	void read(std::istream& o = std::cin) {
		char c;
		int duracion,horasI,minutosI;
		std::cin >> horasI >> c >> minutosI >> duracion;
		inicio = horasI * 60 + minutosI;
		final = inicio + duracion+10; //mas 10 por los min de descanso
	}
	bool operator<(const horas & other)const {
		return final < other.final;
	}
};

inline std::istream & operator>>(std::istream & entrada, horas & h) {
	h.read(entrada);
	return entrada;
}
int numPeliculas(PriorityQueue<horas> &cola) {
	horas aux = cola.top(),aux2;
	int sol=1;
	cola.pop();
	while (!cola.empty()) {
		aux2 = aux;
		while (!cola.empty() && aux2.inicio < aux.final) {
			aux2 = cola.top();
			cola.pop();
		}
		if (aux2.inicio >= aux.final) {
			sol++;
		}
		aux = aux2;
	}
	return sol;
}
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)return false;
	PriorityQueue<horas> cola;
	horas I;
	for (int i = 0; i < N; ++i) {
		cin >> I;
		cola.push(I);
	}
	cout << numPeliculas(cola) << '\n';


	return true;
}
int main() {
	while(resuelveCaso()){}
}