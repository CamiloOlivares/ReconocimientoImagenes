#include "Rec/ReconLib.h"
#include <iostream>
using namespace ReconLib;

int main()
{
	Matriz m(10,11);
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
	m.set(10,9,4);
	m.set(10,8,3);
	m.set(10,7,2);
	m.set(10,6,10);
	m.mostrar();
	std::cout<<"Matriz cargada \n";
	Layer L;
	L.setFilters();
	std::vector<Matriz> convLayer=L.convolution(4,m);

	std::cout<<"Convolución terminada \n";

	std::vector<Matriz> maxPoolLayer;

	for(Matriz f:convLayer){
		//f.mostrar();
		std::cout<<'\n';
		f = L.maxpooling(f);
		maxPoolLayer.push_back(f);
		std::cout<<'\n';
		//f.mostrar();
	}

	for(Matriz mp:maxPoolLayer){
		mp.mostrar();
		std::cout<<'\n';
	}


	std::vector<std::vector<int>> flatenlayer = L.flatten(maxPoolLayer);

	for(std::vector<int> fl:flatenlayer){
		std::cout<< fl.size() <<'\n';
		for(int n:fl){
			std::cout<< n<<' ';
		}
		std::cout<< '\n';
	}
	return 0;
}