#include <iostream>
#include "PriorityQueue.h"
using namespace std;
template <class T1, class T2>
struct C {
	bool operator() (const std::pair<pair<T1, T1>, T2>& lhs, const std::pair<pair<T1, T1>, T2>& rhs) const
	{
		return lhs.first.second < rhs.first.second || (lhs.first.second == rhs.first.second && lhs.second < rhs.second);
	}
};
bool resuelveCaso() {
	int tam,periodo,identificador;
	cin >> tam;
	PriorityQueue<pair<pair<int,int>, int>,C<int,int>> cola; // el primer int periodo segundo acumulado tercero identificador
	if (tam == 0)return false;
	for (int i = 0; i < tam; ++i) {
		cin >> identificador >> periodo;
		cola.push(make_pair(make_pair(periodo,periodo), identificador));
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		pair<pair<int,int>, int> valor = cola.top();
		cola.pop();
		cout << valor.second << '\n';
		valor.first.second += valor.first.first;
		cola.push(valor);
	}

	cout << "----\n";
	return true;

}
int main() {
	while(resuelveCaso()) {}
}