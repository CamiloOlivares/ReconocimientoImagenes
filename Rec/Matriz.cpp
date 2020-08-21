#include "Matriz.h"
#include <vector>
#include <iostream>

namespace ReconLib {

	Matriz::Matriz(int dimension) {
		alto = dimension;
		ancho = dimension;
		numeros = (int*)malloc(sizeof(int) * ancho * alto);
		rellenar(-1);
	}

	Matriz::Matriz(int _ancho, int _alto) {
		alto = _alto;
		ancho = _ancho;
		rellenar(-1);
	}

	int Matriz::get(int i, int j) {
		return numeros[i * ancho + j];
	}

	void Matriz::set(int i, int j, int valor) {
		numeros[i * ancho + j] = valor;
	}

	void Matriz::mostrar()
	{
		for (int i = 0; i < ancho; i++) {
			for (int j = 0; j < alto; j++) {
				std::cout << get(i, j) << " ";
			}
			std::cout << "\n";
		}
	}

	void Matriz::rellenar(int relleno)
	{
		for (int i = 0; i < ancho; i++) {
			for (int j = 0; j < alto; j++) {
				numeros[i * ancho + j] = relleno;
			}
		}
	}
}