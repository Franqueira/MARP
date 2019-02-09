#include "TreeMap_AVL.h"
#include <iostream>
#include <algorithm>
using namespace std;
template <class Clave, class Valor, class Comparador = std::less<Clave>>
class TreeMapEx: public map<Clave,Valor> {

	using clave_valor = typename map<Clave,Valor>::clave_valor;
	using map_t = typename TreeMapEx<Clave, Valor>;
public:

	TreeMapEx(Comparador c = Comparador()) : map<Clave,Valor>(c) {}

	TreeMapEx(map_t const& other) : map<Clave,Valor>(other) {}

protected:
	struct TreeNode;
	using Link = TreeNode * ;
	struct TreeNode {
		clave_valor cv;
		Link iz, dr;
		int altura;
		int tam_i;
		TreeNode(clave_valor const& e, Link i = nullptr, Link d = nullptr,
			int alt = 1,int t=1) : cv(e), iz(i), dr(d), altura(alt),tam_i(t) {}
	};
	Link raiz;
	bool inserta(clave_valor const& cv, Link & a) {
		bool crece = false;
		if (a == nullptr) {
			// se inserta el nuevo par <clave, valor>
			a = new TreeNode(cv);
			++nelems;
			crece = true;
		}
		else if (menor(cv.clave, a->cv.clave)) {
			a->tam_i += 1;
			crece = inserta(cv, a->iz);
			if (crece) reequilibraDer(a);
		}
		else if (menor(a->cv.clave, cv.clave)) {
			crece = inserta(cv, a->dr);
			if (crece) reequilibraIzq(a);
		}
		else { // la clave ya estaba
			crece = false;
		}
		return crece;
	}
	static void rotaDer(Link & k2) {
		Link k1 = k2->iz;
		k2->iz = k1->dr;
		k1->dr = k2;
		k2->altura = std::max(altura(k2->iz), altura(k2->dr)) + 1;
		k1->altura = std::max(altura(k1->iz), altura(k1->dr)) + 1;
		k2 = k1;
		k2->tam_i -= 1;
	}
	static void rotaIzq(Link & k1) {
		Link k2 = k1->dr;
		k1->dr = k2->iz;
		k2->iz = k1;
		k1->altura = std::max(altura(k1->iz), altura(k1->dr)) + 1;
		k2->altura = std::max(altura(k2->iz), altura(k2->dr)) + 1;
		k1 = k2;
		k2->tam_i += 1;

	}
public:
	Clave Kesimo(int k) {
		int acumulados = 0;
		return KesimoPriv(raiz,acumulados,k);
	}
private:
	Clave KesimoPriv(Link k1,int &acumulados,int& k) {
		if (k1->tam_i + acumulados > k) {
			return KesimoPriv(k1->iz, acumulados, k);
		}
		else if (k1->tam_i + acumulados == k)
			return k1->cv.clave;
		else//k1->tam_i + acumulados < k 
			acumulados= acumulados+raiz->tam_i;
		return KesimoPriv(k1->dr, acumulados, k);
	}

};
