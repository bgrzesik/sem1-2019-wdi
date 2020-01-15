//
// Created by Bartłomiej Grzesik on 09/01/2020.
//

#include <iostream>

struct node
{
    int coefficient;
    int exponent;
    node *next;
};

node *sub(node *a, node *b)
{
    node w { 0, 0, nullptr };
    node *n = &w;

    while (a != nullptr && b != nullptr) {
        if (a->exponent > b->exponent) {
            n->next = new node { a->coefficient, a->exponent };

            n = n->next;
            a = a->next;
        } else if (a->exponent < b->exponent) {
            n->next = new node { b->coefficient, b->exponent };

            n = n->next;
            b = b->next;
        } else {
            int coefficient = a->coefficient - b->coefficient;
            if (coefficient != 0) {
                n->next = new node { coefficient, a->exponent };
                n = n->next;
            }
            a = a->next;
            b = b->next;
        }
    }

    return w.next;
}

void print(node *n)
{
    for (; n != nullptr; n = n->next) {
        printf("%dx^%d ", n->coefficient, n->exponent);
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    node a1, a2, a3, a4, a5, a6;
    node b1, b2, b3, b4, b5, b6;

    a1 = { 20, 0, &a2 };
    a2 = { 2, 1, &a3 };
    a3 = { 4, 2, &a4 };
    a4 = { 4, 3, &a5 };
    a5 = { 5, 4, &a6 };
    a6 = { 0, 5, nullptr };

    b1 = { 1, 0, &b2 };
    b2 = { 2, 1, &b3 };
    b3 = { 4, 3, &b4 };
    b4 = { 2, 4, &b5 };
    b5 = { 5, 5, &b6 };
    b6 = { 0, 20, nullptr };

    print(&a1);
    print(&b1);

    node *c = sub(&a1, &b1);
    print(c);
}