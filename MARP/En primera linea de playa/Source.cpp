#include <iostream>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;
struct pr {
	int first;
	int second;
	pr() :first(0), second(0) {}
	pr(int f, int s) :first(f), second(s) {}
	bool operator<(const pr & other) const {
		return first<other.first || (first==other.first && second<other.second);
	}
	bool operator==(const pr & other) const {
		return first==other.first && second==other.second;
	}
};

int numeroTuneles(PriorityQueue<pr> &cola) {
	int numTuneles = 0;
	pr aux1=pr(), aux2=pr();
	while (!cola.empty()) {
		aux1 = cola.top(); // escojo el intervalo que empieza antes y más pequeño
		aux2 = pr();
		cola.pop();
		if (!cola.empty()) {
			 aux2 = cola.top();
		}
		while (!cola.empty() && aux2.first < aux1.second && aux2.second>aux1.second) // miro todos los intervalos que tienen alguna unidad común con el
		{
			cola.pop();
			if(!cola.empty())
			aux2 = cola.top();
		}
		if(aux2.second > aux1.second ||aux2==pr(0,0)) // si no está contenido aux2 en aux1
			numTuneles++;
	}

	return numTuneles;
}
bool resuelveCaso() {
	int N,p,f;
	cin >> N;
	if (N == 0)return false;
	PriorityQueue<pr> cola;
	for (int i = 0; i < N; ++i) {
		cin >> p >> f;
		cola.push(pr(p, f));
	}
	cout << numeroTuneles(cola) << '\n';


	return true;
}
int main() {
	while(resuelveCaso()){}
}
