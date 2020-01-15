//
// Created by Bartłomiej Grzesik on 09/01/2020.
//

#include <iostream>

struct node
{
    int key;
    node *next;
};

void remove(node *n, int times)
{
    node *c = n;
    do {
        int n = 1;
        int key = c->next->key;
        node *c2 = c->next->next;
        do {
            if (key == c2->key) {
                n++;
            }
            c2 = c2->next;
        } while (c2 != c->next);

        if (n == times) {
            c->next = c->next->next;
            node *d = c;
            do {
                if (key == d->next->key) {
                    d->next = d->next->next;
                } else {
                    d = d->next;
                }
            } while (d != c);
        }

        c = c->next;
    } while (c != n);
}

int main(int argc, const char *argv[])
{
    node n1;

    node n9 = { 1, &n1 };
    node n8 = { 12, &n9 };
    node n7 = { 13, &n8 };
    node n6 = { 13, &n7 };
    node n5 = { 8, &n6 };
    node n4 = { 7, &n5 };
    node n3 = { 13, &n4 };
    node n2 = { 2, &n3 };
    n1 = { 1, &n2 };

    node *n = &n1;
    do {
        printf("%d, ", n->key);
        n = n->next;
    } while (n != &n1);
    printf("\n");

    remove(&n1, 3);

    n = &n1;
    do {
        printf("%d, ", n->key);
        n = n->next;
    } while (n != &n1);
    printf("\n");

}