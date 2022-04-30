#pragma once
#pragma once

#include "Point.hpp"
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

const int k = 2;

template <typename T>
struct KDNode {
	T punto[k];
	KDNode* izq, * der;
};

template <typename T>
KDNode<T>* nuevoNodo (vector<T> arr){
	KDNode<T>* temp = new KDNode<T>;
	for (int i = 0; i < k; i++) temp->punto[i] = arr[i];
	temp->izq = temp->der = nullptr;
	return temp;
}

template <typename T>
void eliminar(KDNode<T>* nodo) {
	if (nodo) {
		eliminar((nodo->izq));
		eliminar((nodo->der));
		delete nodo;
	}
}

template <size_t N, typename T>
class KDTree {
public:

	typedef pair<Point<N>, T> tipo;
	size_t dimensiones_;
	size_t tam_;
	KDNode<tipo>* root = nullptr;

	KDTree() {
		dimensiones_ = N;
		tam_ = 0;
	}
	~KDTree() {
		eliminar(root);
	}

};

template <size_t N, typename T>
bool compare(Point<N>& p1, Point<N>& p2) {
	for (int i = 0; i < N; i++) {
		if (p1[i] != p2[i]) return false;
	}
	return true;
}

template <size_t N = 2, typename T>
KDNode<T>* insertRec(KDNode<T>* raiz, vector<T> punto, unsigned depth) {
	if (!raiz) return nuevoNodo(punto);
	unsigned cd = depth % N;
	if (punto[cd] < (raiz->punto[cd])) raiz->izq = insertRec(raiz->izq, punto, depth + 1);
	else raiz->der = insertRec(raiz->der, punto, depth + 1);

	return raiz;
}

template <typename T>
KDNode<T>* insert(KDNode<T>* raiz, vector<T> punto) {
	return insertRec(raiz, punto, 0);
}

template <size_t N = 2, typename T>
bool buscarRec(KDNode<T>* raiz, vector<T> punto, unsigned depth) {
	if (!raiz) return false;
	if (compare(raiz->punto, punto)) return true;

	unsigned cd = depth % N;

	if (punto[cd] < raiz->punto[cd]) return buscarRec(raiz->izq, punto, depth + 1);
	return buscarRec(raiz->der, punto, depth + 1);
}

template <typename T>
bool buscar(KDNode<T>* raiz, vector<T> punto) {
	return buscarRec(raiz, punto, 0);
}