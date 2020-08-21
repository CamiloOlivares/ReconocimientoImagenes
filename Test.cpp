#include "Reconocimiento/ReconLib.h"
using namespace ReconLib;

int main()
{
	Matriz m(3, 3);
	m.set(0, 0, 1);
	m.set(0, 1, 2);
	m.set(0, 2, 3);
	m.set(1, 1, 4);
	m.set(1, 1, 4);
	m.set(1, 1, 4);
	m.set(1, 1, 4);
	m.set(1, 1, 4);
	m.mostrar();
	return 0;
}