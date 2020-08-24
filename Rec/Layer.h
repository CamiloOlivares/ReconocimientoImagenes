/* Estructura de los Layers que componen al programa, input layer, convolutional layer
y polling layer*/

#ifndef Layer_H
#define Layer_H
#include <vector>
#include "Matriz.h"

namespace ReconLib {
	class Layer {
	private:
		
		
	public:
		void setFilters();
		std::vector<Matriz> filters;
		std::vector<Matriz> convolution(int fill_num, Matriz m);
		Matriz maxpooling(Matriz matrix);
		std::vector<std::vector<int>> flatten(std::vector<Matriz> vector_matrix);
		int ReLu(int relu);
		Matriz optimize(int label_num,Matriz matrix,int ages);
		
	};
}

#endif