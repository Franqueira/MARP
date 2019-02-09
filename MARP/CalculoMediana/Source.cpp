#include <iostream>
#include "PriorityQueue.h"
using namespace std;

bool resuelveCaso() {
	int tam, valor,aux1,aux2;
	bool par = true;
	cin >> tam;
	PriorityQueue<int> parteDer;
	PriorityQueue<int, greater<int>> parteIz;
	if (tam == 0)return false;
	/*los dos primeros casos los hago fuera para no tener que hacer
	una comparacion cada vuelta del bucle*/
	cin >> valor;
	parteIz.push(valor);
	cout << 2 * valor << ' ';
	if (tam > 1) {
		cin >> valor;
		aux1 = parteIz.top();
		if (valor < aux1) {
			parteIz.pop();
			parteIz.push(valor);
			parteDer.push(aux1);
		}
		else {
			parteDer.push(valor);
		}
		cout << (valor + aux1) << ' ';
	}
	for (int i = 2; i < tam; ++i) {
		cin >> valor;
		aux1 = parteIz.top();
		aux2 = parteDer.top();
		if (par) { //hay los mismos elementos en las dos partes de la cola
			if (valor <= aux1) {
				parteIz.push(valor);
				cout << 2 * aux1 << ' ';
			}
			else if(valor >= aux2){
				parteDer.push(valor);
				cout << 2 * aux2 << ' ';
			}
			else { // aux1<valor<aux2
				parteIz.push(valor); //daría igual donde insertar en este caso
				cout << 2 * valor << ' ';
			}
			par = false;
		}else { // hay un elemento más en una de las colas
			if (parteIz.size() > parteDer.size()) {
				if (valor <= aux1) {
					parteDer.push(aux1);
					parteIz.pop();
					parteIz.push(valor);
					cout << parteIz.top() + aux1 << ' ';
				}
				else if (valor >= aux2) {
					parteDer.push(valor);
					cout << aux1+aux2 << ' ';
				}
				else { // aux1<valor<aux2
					parteDer.push(valor);
					cout << valor + aux1 << ' ';
				}
			}else { // parteIz.size() < parteDer.size()
				if (valor <= aux1) {
					parteIz.push(valor);
					cout << aux1 + aux2 << ' ';
				}
				else if (valor >= aux2) {
					parteIz.push(aux2);
					parteDer.pop();
					parteDer.push(valor);
					cout << parteDer.top() + aux2 << ' ';
				}
				else { // aux1<valor<aux2
					parteIz.push(valor);
					cout << valor + aux2 << ' ';
				}
			}
			par = true;
		}
	}
	cout << '\n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}