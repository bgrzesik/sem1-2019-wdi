//
// Created by Bartłomiej Grzesik on 09/01/2020.
//

#include <iostream>

struct node
{
//    int val;
    node *next;
};

int is_cyclic(node *n)
{

    node *a = n;
    node *b;

    int size = 0;
    int bump = -1;

    while (a != nullptr) {
        size++;

        b = n;
        bump = 0;
        while (b != a) {
            bump++;
            if (b == a->next) {
                return size - bump + 1;
            }

            b = b->next;
        }

        a = a->next;
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    node a, b, c, d, e, f;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &c;

    std::cout << is_cyclic(&a) << std::endl;

}