#include "mat.h"
#include <iostream>

extern const char* TestMAT(int& s);	//用于实验四，可以放在主函数之前

int main() {
	int s;
	const char* info = TestMAT(s);
	std::cout << info << std::endl;
	return 0;
}