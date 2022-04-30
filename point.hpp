#pragma once
#pragma once

#include <cmath>
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

template <size_t N>
struct Point {
	typedef double* iterador;
	typedef const double* const_iterador;

	Point() {
		for (int i = 0; i < N; i++) {
			coordenadas[i] = 0;
		}
	}

	Point(double valores[N]) {
		for (int i = 0; i < N; i++) {
			coordenadas.push_back(valores[i]);
		}
	}

	size_t tam() const {
		return N;
	}

	vector<double> coordenadas;
};

template <size_t N>
double distancia(const Point<N>& primero, const Point<N>& segundo) {
	double resultado = 0.0;
	for (size_t i = 0; i < N; ++i) {
		double temp = (primero[i] - segundo[i]);
		resultado += pow(temp, 2);
	}
	return sqrt(resultado);
}