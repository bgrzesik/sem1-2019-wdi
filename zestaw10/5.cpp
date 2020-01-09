//
// Created by Bartłomiej Grzesik on 26/12/2019.
//

#include <cstdio>

struct node
{
    int val;
    node *next;
};

void add(node **n, int val)
{
    node *a = new node;
    a->val = val;

    if (*n == nullptr) {
        a->next = nullptr;
        *n = a;
    } else {
        a->next = (*n);
        *n = a;
    }
}

void release(node *n)
{
    if (n != nullptr) {
        release(n->next);
        delete n;
    }
}

void mangle(node **pn)
{
    node *n = *pn;

    node *splits[10];
    node *splits_next[10];

    for (int i = 0; i < 10; i++) {
        splits_next[i] = splits[i] = nullptr;
    }

    while (n != nullptr) {
        node *next = n->next;
        n->next = nullptr;

        if (splits[n->val % 10] == nullptr) {
            splits[n->val % 10] = n;
            splits_next[n->val % 10] = n;
        } else {
            splits_next[n->val % 10]->next = n;
            splits_next[n->val % 10] = n;
        }

        n = next;
    }

    node w = { 0, nullptr };
    node *p = &w;

    for (int i = 0; i < 10; ++i) {
        p->next = splits[i];
        p = splits_next[i];
    }

    *pn = w.next;
}

void print(node *n)
{
    printf("{ ");
    while (n != nullptr) {
        printf("%d, ", n->val);
        n = n->next;
    }
    printf("}\n");
}

int main(int argc, const char *argv[])
{
    node *n = nullptr;
    add(&n, 2);
    add(&n, 14);
    add(&n, 3);
    add(&n, 1);
    add(&n, 4);
    add(&n, 15);
    add(&n, 9);
    add(&n, 12);
    add(&n, 17);
    add(&n, 18);
    add(&n, 6);
    add(&n, 5);
    add(&n, 8);
    add(&n, 10);
    add(&n, 0);
    add(&n, 11);
    add(&n, 7);
    add(&n, 13);
    add(&n, 16);
    add(&n, 19);

    print(n);
    mangle(&n);
    print(n);

    release(n);
}