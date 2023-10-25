#include <iostream>
#include <iomanip>
int main() {
	double x1 = 1.00E+21;
	double x2 = 17.0;
	double x3 = -10.0;
	double x4 = 130.0;
	double x5 = -1.00E+21;
	double s1 = x1 + x2 + x3 + x4 + x5;
	std::cout << "s1 " << s1 << std::endl;
	return 0;
}