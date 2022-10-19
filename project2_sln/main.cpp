#include <iostream>
#include "Queue.h"

using namespace std;

extern const char* TestQUEUE(int &s);

int main() {
//    std::cout << "Hello, World!" << std::endl;
    int s;
    const char* e = TestQUEUE(s);
    cout << e << endl;
    return 0;
}
