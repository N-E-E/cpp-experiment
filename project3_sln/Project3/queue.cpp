//
// Created by Mr.K on 2022/10/14.
//

#include "Queue.h"
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

QUEUE::QUEUE(int m) : head(0), tail(0), elems(new int[m]), max(m) {
    //cout << "ctor1: max=" << max << endl;

}

QUEUE::QUEUE(const QUEUE& q) : head(q.head), tail(q.tail), elems(new int[q.max]), max(q.max) {
    //cout << "ctor2" << endl;
    for (int i = 0; i < q.max; i++) {
        elems[i] = q.elems[i];
    }
}

QUEUE::QUEUE(QUEUE&& q) noexcept : elems(q.elems), max(q.max), head(q.head), tail(q.tail) {
    //cout << "ctor3" << endl;
    *(int**)&q.elems = nullptr;
    *(int*)&q.max = 0;
    q.tail = 0;
    q.head = 0;
}

QUEUE::operator int() const noexcept {
    //cout << "int()" << endl;
    if (max == 0) return 0;
    return (tail + max - head) % max;
}

int QUEUE::size() const noexcept {
    //cout << "size" << endl;
    return max;
}

QUEUE& QUEUE::operator<<(int e) {

    //cout << "op<<" << e << endl;
    //cout << "head=" << head << ", tail=" << tail << "max=" << max << endl;
    if ((tail + 1) % max == head) {
        throw "QUEUE is full!";
        return *this;
    };
    elems[tail] = e;
    tail = (tail + 1) % max;
    return *this;
}

QUEUE& QUEUE::operator>>(int& e) {
    if (head == tail) throw "QUEUE is empty!";
    e = elems[head];
    //cout << "op>>" << e << endl;
    //cout << "head=" << head << ", tail=" << tail << endl;
    head = (head + 1) % max;
    return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& q) {
    //cout << "op==" << endl;
    if (elems == q.elems) return *this;
    if (elems != nullptr) {
        delete[]elems;
        *(int**)&elems = nullptr;
    }
    *(int**)&elems = new int[q.max];
    for (int i = 0; i < q.max; i++) {
        elems[i] = q.elems[i];
    }
    *(int*)&max = q.max;
    head = q.head;
    tail = q.tail;
    return *this;
}

QUEUE& QUEUE::operator=(QUEUE&& q) noexcept {
    //cout << "op==move" << endl;
    if (this == &q) return *this;
    if (elems != nullptr) {
        delete[]elems;
        *(int**)&elems = nullptr;
    }
    *(int**)&elems = q.elems;  // ÒÆ¶¯¸³Öµ
    *(int**)&q.elems = nullptr;
    *(int*)&max = q.max;
    head = q.head;
    tail = q.tail;
    *(int*)&q.max = 0;
    q.tail = 0;
    q.head = 0;
    return *this;
}

char* QUEUE::print(char* s) const noexcept {
    /*cout << "test print:" << endl;
    test_print();*/
    //strcpy(s, "");
    for (int i = head; i != tail; i = (i + 1) % max) {
        char* ss = s + strlen(s);
        /*if ((i + 1) % max == tail) {
            sprintf(ss, "%d", elems[i]);
        }
        else {
            sprintf(ss, "%d,", elems[i]);
        }*/
        sprintf(ss, "%d,", elems[i]);
    }
    //cout << s << endl;
    return s;
}

QUEUE::~QUEUE() {
    //cout << "dtor" << endl;
    if (elems != nullptr) {
        delete[]elems;
        *(int**)&elems = nullptr;
    }
    *(int*)&max = 0;
    head = 0;
    tail = 0;
}
