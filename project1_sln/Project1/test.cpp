// project1.cpp: 定义应用程序的入口点。
//

#include "Queue.h"

extern const char* TestQueue(int& s);

using namespace std;

int main()
{
	int s = 6;
	/*Queue* p = (Queue*)malloc(sizeof(struct Queue));
	initQueue(p, 10);*/
	const char* e = TestQueue(s);
	return 0;
}
