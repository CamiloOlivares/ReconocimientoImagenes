#ifndef ReconLib_H
#define ReconLib_H
#pragma once

/* Estructura de los Layers que componen al programa, input layer, convolutional layer
y polling layer*/
#include <vector>

namespace ReconLib {
	class Layer {
		std::vector<std::vector<std::vector<int>>> convolution(int fill_num);
		std::vector<std::vector<int>> maxpooling(std::vector<std::vector<int>> matrix);
		std::vector<std::vector<int>> flatten(std::vector<std::vector<std::vector<int>>> vector_matrix);
		int ReLu(int ReLu);
		std::vector<std::vector<int>> optimize(int label_num,std::vector<std::vector<int>> matrix,int ages);
	};
}


#endif