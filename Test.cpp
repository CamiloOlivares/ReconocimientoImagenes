#include "Rec/ReconLib.h"
#include <iostream>
using namespace ReconLib;

int main()
{
	std::cout << "hola";
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