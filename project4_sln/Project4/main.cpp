#include "mat.h"
#include <iostream>

extern const char* TestMAT(int& s);	//����ʵ���ģ����Է���������֮ǰ

int main() {
	int s;
	const char* info = TestMAT(s);
	std::cout << info << std::endl;
	return 0;
}