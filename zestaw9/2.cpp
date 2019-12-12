//
// Created by Bartłomiej Grzesik on 12/12/2019.
//


#include <climits>
#include <cstdio>

struct node
{
    int val;
    int idx;
    node *next;
};


void init(node **node)
{
}

int value(node *n, int idx)
{
    while (n->idx < idx and n->next != nullptr) {
        n = n->next;
    }

    if (n->idx == idx) {
        return n->val;
    } else {
        return 0;
    }
}

void set(node **n, int idx, int val)
{
    if (*n == nullptr) {
        *n = new node;
        (*n)->next = nullptr;
        (*n)->val = val;
        (*n)->idx = idx;
        return;
    }

    node root;
    root.next = *n;
    root.idx = INT_MIN;
    root.val = 666;

    node *i = &root;

    while (i->next->next != nullptr and i->next->idx < idx) {
        i = i->next;
    }

    if (i->next->idx == idx) {
        i->next->val = val;

        if (val == 0) {
            node *next = i->next->next;
            delete i->next;
            i->next = next;
            return;
        }

    } else {

        i = i->next;
        node *next = i->next;
        i->next = new node;
        i->next->idx = idx;
        i->next->val = val;
        i->next->next = next;
    }

    *n = root.next;
}

void print_el(node *n)
{
    printf("{ ");
    for (node *i = n; i != nullptr; i = i->next) {
        printf("(%d = %d), ", i->idx, i->val);
    }
    printf("} \n");
}

int main()
{
    node *n = nullptr;
    set(&n, 10, 11);
    print_el(n);
    set(&n, 20, 21);
    print_el(n);
    set(&n, 30, 31);
    print_el(n);
    set(&n, 40, 41);
    print_el(n);
    set(&n, 10, 881);
    print_el(n);
    set(&n, 20, 0);
    print_el(n);

    printf("%d\n", value(n, 10));
    printf("%d\n", value(n, 30));
    printf("%d\n", value(n, 1012));
}