//
// Created by Bartłomiej Grzesik on 26/12/2019.
//

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

node *_reverse(node *n, node *first)
{
    if (n->next == nullptr) {
        first->val = n->val;
        return first->next;
    }

    int val = n->val;

    node *put = _reverse(n->next, first);
    put->val = val;
    return put->next;
}

void reverse(node *n)
{
    _reverse(n, n);
}

int main(int argc, const char *argv[])
{
    node *n = nullptr;
    add(&n, 1);
    add(&n, 2);
    add(&n, 3);
    add(&n, 4);
    add(&n, 5);
    add(&n, 6);

    reverse(n);

    release(n);
}