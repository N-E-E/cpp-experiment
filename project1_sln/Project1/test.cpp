// project1.cpp: ����Ӧ�ó������ڵ㡣
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
