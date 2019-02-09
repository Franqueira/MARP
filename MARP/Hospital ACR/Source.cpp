#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;
template <class T1,class T2>
struct C{
	bool operator() (const std::pair<pair<T1,T1>, T2>& lhs, const std::pair<pair<T1,T1>, T2>& rhs) const
	{
		return lhs.first.first > rhs.first.first || (lhs.first.first == rhs.first.first && lhs.first.second < rhs.first.second);
	}
};
bool resuelveCaso() {
	int tam, urgencia;
	PriorityQueue<pair<pair<int,int>, string>,C<int,string>> cola; // el primer par es la urgencia y el tiempo que lleva (en que i se hizo)
	string nombre;
	char operacion;
	cin >> tam;
	if (tam == 0)return false;
	for (int i = 0; i < tam; ++i) {
		cin >> operacion;
		if (operacion == 'I') {
			cin >> nombre >> urgencia;
			cola.push(make_pair(make_pair(urgencia,i), nombre));
		}
		else if (operacion == 'A') {
			nombre = cola.top().second;
			cola.pop();
			cout << nombre << '\n';
		}
	}
	cout << "----\n";
	return true;
}
int main() {
	while (resuelveCaso()) {}
}