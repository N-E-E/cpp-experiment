#include "Queue.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

void initQueue(Queue* const p, int m)
{
	*((int**)&p->elems) = (int*)malloc(sizeof(int) * m);
	*((int*)&p->max) = m;
	p->head = 0;
	p->tail = 0;
}

void initQueue(Queue* const p, const Queue& s)
{
	*(int*)&p->max = s.max;
	*(int**)&p->elems = new int[p->max];
	p->head = s.head;
	p->tail = s.tail;
	for (int k = 0; k < s.max; k++) {
		p->elems[k] = s.elems[k];
	}
}

void initQueue(Queue* const p, Queue&& s)
{
	*(int**)&p->elems = s.elems;
	*(int*)&p->max = s.max;
	p->head = s.head;
	p->tail = s.tail;
	*(int**)&s.elems = nullptr;
	*(int*)&s.max = 0;
	s.head = 0;
	s.tail = 0;
}

int number(const Queue* const p)
{
	if (p->max == 0) return 0;
	return (p->tail + p->max - p->head) % p->max;
}

int size(const Queue* const p)
{
	return p->max;
}

Queue* const enter(Queue* const p, int e)
{
	/*if ((p->tail + 1) % p->max == p->head) throw "Queue is full!";
	p->elems[p->tail++] = e;
	return p;*/
	int t = p->tail;
	int h = p->head;
	int m = p->max;

	if ((t + 1) % m == h) {
		throw "Queue is full!";
	}
	p->elems[t] = e;
	t++;
	t = t % m;
	p->tail = t;
	return p;
}

Queue* const leave(Queue* const p, int& e)
{
	int h;
	h = p->head;
	int m;
	m = p->max;
	int t;
	t = p->tail;
	if (t == h) {
		throw "Queue is empty!";
	}
	e = p->elems[h];
	h++;
	h = h % m;
	p->head = h;
	return p;
}

Queue* const assign(Queue* const p, const Queue& q)
{
	if (p == &q) return p;
	if (p->elems != nullptr) {
		delete[]p->elems;
		*(int**)&p->elems = nullptr;
	}
	*(int**)&p->elems = new int[q.max];
	*(int*)&p->max = q.max;
	p->head = q.head;
	p->tail = q.tail;
	for (int i = 0; i < q.max; i++) {
		p->elems[i] = q.elems[i];
	}
	return p;
}

Queue* const assign(Queue* const p, Queue&& q)
{
	if (p == &q)	return p;
	if (p->elems != nullptr) {
		delete[]p->elems;
		*(int**)&p->elems = nullptr;
	}
	*(int**)&p->elems = q.elems;
	*(int*)&p->max = q.max;
	p->tail = q.tail;
	p->head = q.head;
	*(int*)&q.max = 0;
	*(int**)&q.elems = nullptr;
	q.tail = q.head = 0;
	return p;
}

char* print(const Queue* const p, char* s)
{
	int m = p->max;
	for (int i = p->head; i != p->tail; i = (i + 1) % m) {
		char* ss = s + strlen(s);
		sprintf(ss, "%d,", p->elems[i]);
	}
	////printf("%s", s);
	return s;
}

void destroyQueue(Queue* const p)
{
	delete []p->elems;
	*(int**)&p->elems = nullptr;
	*(int*)&p->max = 0;
}
