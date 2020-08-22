#ifndef Matriz_H
#define Matriz_H


namespace ReconLib {

	class Matriz
	{
	public:
		int* numeros;
		int alto;
		int ancho;
		Matriz(int ancho, int alto);
		Matriz(int dimension);
		void mostrar();
		void rellenar(int relleno);
		int get(int i, int j);
		void set(int i, int j, int valor);

	};
}

#endif

