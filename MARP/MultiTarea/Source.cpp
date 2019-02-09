#include <iostream>
#include "PriorityQueue.h"
using namespace std;
template <class T1, class T2>
struct C {
	bool operator() (const std::pair<pair<T1,T1>, T2>& lhs, const std::pair<pair<T1,T1>, T2>& rhs) const
	{
		return lhs.first.first< rhs.first.first ;
	}
};
bool resuelveCaso() {
	PriorityQueue<pair<pair<int, int>,int>> cola;//primer int comienzo final periodo
	int N, M, T;
	bool sol=false;
	int comienzo, final,periodo;
	cin >> N >> M >> T;
	if (!cin) // fin de la entrada
		return false;
	for (int i = 0; i < N; ++i) {
		cin >> comienzo >> final;
		if(comienzo<T)
			cola.push(make_pair(make_pair(comienzo, final),0));
	}
	for (int i = 0; i < M; ++i) {
		cin >> comienzo >> final >> periodo;
		if (comienzo<T)
		cola.push(make_pair(make_pair(comienzo, final),periodo));
	}
	pair<pair<int,int>, int> intervalo1,intervalo2;
	if (!cola.empty()) {
		intervalo2 = cola.top();
		cola.pop();
		if (intervalo2.second != 0 && intervalo2.first.first + intervalo2.second<T)
			cola.push(make_pair(make_pair(intervalo2.first.first + intervalo2.second, intervalo2.first.second + intervalo2.second), intervalo2.second));
	}
	while (!cola.empty() && intervalo2.first.first<T && !sol) {
		intervalo1 = intervalo2;
		intervalo2 = cola.top();
		if (intervalo1.first.second > intervalo2.first.first) {
			sol = true;
		}
		cola.pop();
		if (intervalo2.second != 0 && intervalo2.first.first + intervalo2.second<T)
			cola.push(make_pair(make_pair(intervalo2.first.first + intervalo2.second, intervalo2.first.second + intervalo2.second), intervalo2.second));
	}
	if (sol)cout << "SI\n";
	else cout << "NO\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}