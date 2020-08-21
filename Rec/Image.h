#pragma once
#ifndef ReconLib_H
#define ReconLib_H
#include <vector>
#include <string>

namespace ReconLib {
	class Image {
	public:
		Image(/*string image_route*/);
		std::vector<std::vector<int>> get_pixels();
		int get_pixel_value(int x_pos,int y_pos);
		int get_heigth();
		int get_width();
	private:
		std::vector<std::vector<int>> pixel_matrix;
		int heigth;
		int width;
	};
}

#endif
