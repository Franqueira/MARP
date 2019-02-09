#include <iostream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct horas {
	int inicio;
	int final;
	void read(std::istream& o = std::cin) {
		cin >> inicio >> final; 
	}
	bool operator<(const horas & other)const {
		return inicio < other.inicio; //ordeno por orden de finalización de las actividades
	}
};

inline std::istream & operator>>(std::istream & entrada, horas & h) {
	h.read(entrada);
	return entrada;
}
struct horas2 {
	int inicio;
	int final;
	bool operator<(const horas2 & other)const {
		return final < other.final; //ordeno por orden de finalización de las actividades
	}
};
int numAmigos(PriorityQueue<horas> &cola) {
	horas aux;
	horas2 aux2;
	PriorityQueue<horas2> colaAmigos; //cola con la última actividad que fue cada amigo
	int sol = 0;
	while (!cola.empty()) {
		aux = cola.top();
		cola.pop();
		aux2.inicio = aux.inicio;
		aux2.final = aux.final;
		if (!colaAmigos.empty()) {
				if (aux2.inicio < colaAmigos.top().final) { // si es menor que el que acaba antes de mis amigos
					colaAmigos.push(aux2); //necesito otro amigo
				}
				else { // si no hago que el amigo que antes termina la atienda y pasa a tener la actividad aux
					colaAmigos.pop();
					colaAmigos.push(aux2);
				}
		}
		else
			colaAmigos.push(aux2);
		//cojo el máximo entre la anterior solución y el numero de amigos que necesito en este momento.
		sol = max(sol, colaAmigos.size()-1); 
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
	cout << numAmigos(cola) << '\n';


	return true;
}
int main() {
	while(resuelveCaso()){}
}
/*int numAmigos(PriorityQueue<horas> &cola) {
	horas aux = cola.top(),aux2;
	PriorityQueue<horas> colaAmigos;
	int sol=0;
	cola.pop();
	while (!cola.empty()) {
		aux2.inicio = 0;
		aux2.final = 0;
		while (!cola.empty() && aux2.inicio < aux.final) {
			//estos son los que no puedo atender
			if (aux2.final != 0) {
				if (!colaAmigos.empty()) {
					if (aux2.inicio < colaAmigos.top().final) {// si es menor que el que acaba antes de mis amimgos, es decir necesito a otro amigo
						colaAmigos.push(aux2);
					}
					else {
						colaAmigos.pop();
						colaAmigos.push(aux2);
					}
				}
				else colaAmigos.push(aux2);
			sol = max(sol, colaAmigos.size());
			}
			aux2 = cola.top();
			cola.pop();
		}
		if (cola.empty() && aux2.inicio < aux.final) {
			if (aux2.final != 0) {
				if (!colaAmigos.empty()) {
					if (aux2.inicio < colaAmigos.top().final) { // si es menor que el que acaba antes de mis amimgos
						colaAmigos.push(aux2);
					}
					else { // si no hago que el amigo que antes termina la atienda y pasa a tener aux2
						colaAmigos.pop();
						colaAmigos.push(aux2);
					}
				}
				else colaAmigos.push(aux2);
				sol = max(sol, colaAmigos.size());
			}
		}
		aux = aux2;
	}
	return sol;
}*/