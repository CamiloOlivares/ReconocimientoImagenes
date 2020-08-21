#include "Image.h"
#include <vector>
#include <string>
namespace ReconLib {


	Image::Image(/*std::string image_route*/) {
		
	}

	int heigth;

	int width;

	std::vector<std::vector<int>> get_pixels();

	int get_pixel_value(int x_pos, int y_pos);

	int get_heigth();

	int get_width();

	std::vector<std::vector<int>> pixel_matrix;

	
}

