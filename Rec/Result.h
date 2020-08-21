#ifndef ReconLib_H
#define ReconLib_H
#pragma once
#include "label.h"
#include <vector>


namespace ReconLib {
	class Result {
	public:
		Result(std::vector<label> labels);
		label get_label(std::string label_name);
	private:
		std::vector<label> labels;
	};
}

#endif