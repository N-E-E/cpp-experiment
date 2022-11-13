#include "stack.h"

STACK::STACK(int m) : q(m), QUEUE(m)
{
}

STACK::STACK(const STACK& s) : q(s.q), QUEUE(s)
{
}

STACK::STACK(STACK&& s) noexcept : q((QUEUE&&)s.q), QUEUE((QUEUE&&)s)
{
}

int STACK::size() const noexcept
{
    return 2 * QUEUE::size();
}

STACK::operator int() const noexcept
{
    /*if (max == 0) return 0;
    return (tail + max - head) % max;*/
    return QUEUE::operator int() + q.operator int();
}

STACK& STACK::operator<<(int e)
{
    if (q == q.size() - 1) throw "STACK is full!";
    if (QUEUE::operator int() < QUEUE::size() - 1) {
        QUEUE::operator<<(e);
    }
    else {
        q.operator<<(e);
    }
    return *this;
}

STACK& STACK::operator>>(int& e)
{
    if (QUEUE::operator int() == 0) throw "STACK is empty!";
    int num, tmp;
    if (q != 0) {
        num = q;
        for (int i = 1; i < num; i++) {
            q >> tmp;
            q << tmp;
        }
        q >> e;
    }
    else {
        num = QUEUE::operator int();
        for (int i = 1; i < num; i++) {
            QUEUE::operator>>(tmp);
            QUEUE::operator<<(tmp);
        }
        QUEUE::operator>>(e);
    }
    return *this;
}

STACK& STACK::operator=(const STACK& s)
{
    q = s.q;
    QUEUE::operator=(s);
    return *this;
}

STACK& STACK::operator=(STACK&& s) noexcept
{
    q = (QUEUE&&)s.q;
    QUEUE::operator=((STACK&&)s);
    return *this;
}

char* STACK::print(char* b) const noexcept
{
    QUEUE::print(b);
    q.print(b);
    return b;
}

STACK::~STACK() noexcept
{
    q.~QUEUE();
    QUEUE::~QUEUE();
}
