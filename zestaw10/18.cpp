//
// Created by Bartłomiej Grzesik on 15/01/2020.
//

#include <cstdio>


struct node
{
    int value;
    node *next;
};


void remove_growth(node *n)
{
    node w;
    w.value = -1;
    w.next = n;

    node *c = &w;
    node *longest = &w;
    node *start;

    int clen = 0;
    int len = -1;

    while (c->next != nullptr) {
        int a = c->next->value;
        start = c;

        c = c->next;

        while (c->next != nullptr and c->next->value >= a) {
            clen++;
            a = c->next->value;
            c = c->next;
        }

        if (clen > len) {
            len = clen + 1;
            longest = start;
        }
        clen = 0;
    }

    for (int i = 0; i < len; ++i) {
        longest->next = longest->next->next;
    }

    n->value = w.next->value;
    n->next = w.next->next;
}

int main(int argc, char *argv[])
{
    node n7 = { 1, nullptr };
    node n6 = { 13, &n7 };
    node n5 = { 8, &n6 };
    node n4 = { 7, &n5 };
    node n3 = { 5, &n4 };
    node n2 = { 2, &n3 };
    node n1 = { 1, &n2 };

    for (node *n = &n1; n != nullptr; n = n->next) {
        printf("%d, ", n->value);
    }
    printf("\n");

    remove_growth(&n1);

    for (node *n = &n1; n != nullptr; n = n->next) {
        printf("%d, ", n->value);
    }
    printf("\n");
}