#include "cLens.h"
#include <stdio.h>
#include <iostream>


int main() {

	cLens lens;

	lens.Set_r(1, 100);
	lens.Set_r(2, -100);
	lens.Set_d(1, 10);
	lens.Set_N(0, 1.0);
	lens.Set_N(1, 1.5);
	lens.Set_N(2, 1.0);


	double focal_length;
	focal_length = lens.FocalLength();
	std::cout << focal_length << std::endl;

}