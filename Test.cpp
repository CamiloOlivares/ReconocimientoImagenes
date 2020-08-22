#include "Rec/ReconLib.h"
#include <iostream>
using namespace ReconLib;

int main()
{
	Matriz m(10, 10);
	m.set(0, 0, -1);
	m.set(0, 1, -1);
	m.set(0, 2, 1);
	m.set(0, 3, 1);
	m.set(1, 0, 2);
	m.set(1, 1, 1);
	m.set(1, 2, 1);
	m.set(1, 3, 2);
	m.set(2, 0, 1);
	m.set(2, 1, 1);
	m.set(2, 2, 3);
	m.set(2, 3, 1);
	m.set(3, 0, 5);
	m.set(3, 1, 1);
	m.set(3, 2, 6);
	m.set(3, 3, 1);
	m.mostrar();
	std::cout<<'\n';
	Layer L;
	L.setFilters();
	std::vector<Matriz> convLayer=L.convolution(3,m);
	for(Matriz f:convLayer){
		f.mostrar();
	}
	return 0;
}