#include "kdtree.hpp"
#include <time.h>
#include <random>

using namespace std;

int main() {

	srand(time(NULL));
	const size_t tam = 2;

	vector<Point<tam>> puntos;

	for (int i = 0; i < 10; i++) {
		double valores[tam];
		for (int j = 0; j < tam; j++) {
			valores[j] = rand() % 100;
		}

		Point<tam> punto(valores);
		puntos.push_back(punto);
	}

	KDNode<double>* raiz = nullptr;

	for (int i = 0; i < puntos.size(); i++) {
		raiz = insert(raiz, puntos[i].coordenadas);

	}
}