#include "Queue.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

void initQueue(Queue* const p, int m)
{
	*((int**)& p->elems) = (int*)malloc(sizeof(int) * m);
	*((int*) & p->max) = m;
	p->head = 0;
	p->tail = 0;
}

void initQueue(Queue* const p, const Queue& s)
{
	*((int**)&p->elems) = (int*)malloc(sizeof(s.elems));
	*((int*)&p->max) = s.max;
	p->head = s.head;
	p->tail = s.tail;
}

void initQueue(Queue* const p, Queue&& s)
{
	*((int**)&p->elems) = s.elems;
	*((int**)& s.elems) = nullptr;  // ?
	*((int*)&p->max) = s.max;
	p->head = s.head;
	p->tail = s.tail;
}

int number(const Queue* const p)
{
	return (p->tail + p->max - p->head) % p->max;
}

int size(const Queue* const p)
{
	return p->max;
}

Queue* const enter(Queue* const p, int e)
{
	//if ((p->tail + 1) % p->max == p->head) return nullptr;
	p->elems[p->tail++] = e;
	return p;
}

Queue* const leave(Queue* const p, int& e)
{
	e = p->elems[p->head++];
	return p;
}

Queue* const assign(Queue* const p, const Queue& q)
{
	if (p->elems != nullptr) {
		int* p0 = p->elems;
		free(p0);
	}
	initQueue(p, q);
	return p;
}

Queue* const assign(Queue* const p, Queue&& q)
{
	if (p->elems != nullptr) {
		int* p0 = p->elems;
		free(p0);
	}
	initQueue(p, q);
	return p;
}

char* print(const Queue* const p, char* s)
{
	int ind = p->head;
	while (ind != p->tail) {
		sprintf_s(s, sizeof(s)/sizeof(char), "%s,", p->elems[ind]);
	}
	return s;
}

void destroyQueue(Queue* const p)
{
	free(p->elems);
	free(p);

}
