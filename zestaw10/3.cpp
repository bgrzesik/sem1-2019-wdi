//
// Created by Bartłomiej Grzesik on 26/12/2019.
//

#include <cstdint>

struct node
{
    int val;
    node *next;
};

#define NODE_INIT ((node) { INT32_MIN, nullptr })

void add(node *n, int val)
{
    while (n->next != nullptr and n->next->val < val) {
        n = n->next;
    }

    node *next = n->next;
    n->next = new node;
    n->next->val = val;
    n->next->next = next;
}

void merge(node *n, node *n2)
{
    n2 = n2->next;
    while (n2 != nullptr) {
        if (n->next != nullptr and n->next->val < n2->val) {
            n = n->next;
        } else {
            node *next = n->next;
            n->next = n2;

            n2 = n2->next;

            n->next->next = next;
        }

    }
}

node *_merge_recur(node *n, node *n2)
{
    if (n == nullptr and n2 == nullptr) {
        return nullptr;
    }

    node *a = new node;
    if (n2 == nullptr or (n != nullptr and n->val < n2->val)) {
        a->val = n->val;
        a->next = _merge_recur(n->next, n2);
    } else {
        a->val = n2->val;
        a->next = _merge_recur(n, n2->next);
    }
    return a;
}

node merge_recur(node *n, node *n2)
{
    node a = NODE_INIT;
    a.next = _merge_recur(n->next, n2->next);
    return a;
}

void release(node *n)
{
    while (n->next != nullptr) {
        node *r = n->next;
        n->next = r->next;
        delete r;
    }
}


int main(int argc, const char *argv[])
{
    {
        node n = NODE_INIT;
        add(&n, 10);
        add(&n, 20);
        add(&n, 10);
        node n2 = NODE_INIT;
        add(&n2, 13);
        add(&n2, 12);
        add(&n2, 30);

        merge(&n, &n2);

        release(&n);
    }
    {
        node n = NODE_INIT;
        add(&n, 10);
        add(&n, 20);
        add(&n, 10);
        node n2 = NODE_INIT;
        add(&n2, 13);
        add(&n2, 12);
        add(&n2, 30);

        node n3 = merge_recur(&n, &n2);
        release(&n);
        release(&n2);
        release(&n3);
    }
}