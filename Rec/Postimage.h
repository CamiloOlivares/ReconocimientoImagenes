#ifndef ReconLib_H
#define ReconLib_H
#pragma once
#include <iostream>
#include "label.h"

namespace ReconLib {
	class Postimage {
	public:
		Postimage(std::string image_route);
		void joinStruct(std::vector<label> labels, std::string export_route);
		void pointDraw(std::vector<label> labels, std::string export_route);
		int angleBtwStructs(label label1, label label2);
		void setRutaInput(std::string input_route);
		void setRutaOutput(std::string output_route);
		void setLabels(std::vector<label> labels);
	private:
		std::vector<label> labels;
		std::string inputRoute;
		std::string outputRoute;
	};
}

#endif