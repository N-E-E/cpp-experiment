#include "queue.h"
#include "stack.h"
#include <iostream>

extern const char* TestSTACK(int& s);

int main() {
	int s;
	const char* info = TestSTACK(s);
	std::cout << info << std::endl;
	return 0;
}