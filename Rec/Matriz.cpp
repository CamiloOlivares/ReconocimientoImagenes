#include "Matriz.h"
#include <vector>
#include <iostream>

namespace ReconLib {

	Matriz::Matriz(int dimension) {
		this->alto = dimension;
		this->ancho = dimension;
		this->numeros = (int*)malloc(sizeof(int) * ancho * alto);
		rellenar(-1);
	}

	Matriz::Matriz(int _ancho, int _alto) {
		this->alto = _alto;
		this->ancho = _ancho;
		this->numeros = (int*)malloc(sizeof(int) * ancho * alto);
		rellenar(-1);
	}

	int Matriz::get(int i, int j) {
		return this->numeros[i * ancho + j];
	}

	void Matriz::set(int i, int j, int valor) {
		this->numeros[i * ancho + j] = valor;
	}

	void Matriz::mostrar()
	{
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				std::cout << get(i, j) << " ";
			}
			std::cout << "\n";
		}
	}

	void Matriz::rellenar(int relleno)
	{
		for (int i = 0; i < this->alto; i++) {
			for (int j = 0; j < this->ancho; j++) {
				this->numeros[i * this->ancho + j] = relleno;
			}
		}
	}
}