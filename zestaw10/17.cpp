//
// Created by Bartłomiej Grzesik on 15/01/2020.
//

#include <cstdio>

/*
 Dana jest lista zawierająca ciąg obustronnie domkniętych przedziałów.
 Krańce przedziałów określa uporządkowana para liczb całkowitych.
 Proszę napisać stosowne deklaracje oraz funkcję redukującą liczbę elementów listy.
 Na przykład lista: [15,19] [2,5] [7,11] [8,12] [5,6] [13,17]
 powinien zostać zredukowany do listy: [13,19] [2,6] [7,12]
 */

struct node
{
    int min;
    int max;
    node *next;
};

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void reduce(node *n)
{
    node *c = n;

    while (c->next != nullptr) {

        node *next = c->next;
        node *s = n;

        while (s != nullptr and s != next) {
            if ((next->min >= s->min and next->min <= s->max) or
                (next->max >= s->min and next->max <= s->max) or
                (next->min <= s->min and next->max >= s->max)) {

                s->min = min(next->min, s->min);
                s->max = max(next->max, s->max);

                // delete old next?
                c->next = c->next->next;
                c = s;
                break;
            }
            s = s->next;

            if (s == nullptr || s == next) {
                c = c->next;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    node n7 = { 1, 20, nullptr };
    node n6 = { 13, 17, &n7 };
    node n5 = { 5, 6, &n6 };
    node n4 = { 8, 12, &n5 };
    node n3 = { 7, 11, &n4 };
    node n2 = { 2, 5, &n3 };
    node n1 = { 15, 19, &n2 };

    reduce(&n1);

    for (node *n = &n1; n != nullptr; n = n->next) {
        printf("[%d %d], ", n->min, n->max);
    }
}