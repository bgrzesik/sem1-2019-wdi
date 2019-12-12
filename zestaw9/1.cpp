//
// Created by Bartłomiej Grzesik on 12/12/2019.
//


struct node
{
    int idx;
    node *next;
};

void add_node(node **n, int val)
{
    if (*n == nullptr) {
        *n = new node;
        (*n)->idx = val;
        (*n)->next = nullptr;
        return;
    }

    node *i = *n;

    if (i->idx > val) {
        *n = new node;
        (*n)->idx = val;
        (*n)->next = i;
        return;
    }

    while (i->next != nullptr && i->idx < val) {
        i = i->next;
    }

    if (i->idx == val) {
        return;
    }

    node *next = i->next;
    i->next = new node;
    i->next->idx = val;
    i->next->next = next;
}

void remove_node(node **n, int val)
{
    if (*n == nullptr) {
        return;
    }

    if ((*n)->idx == val) {
        *n = (*n)->next;
        return;
    }

    node *i = *n;
    while (i->next != nullptr and i->next->idx != val) {
        i = i->next;
    }

    if (i->next != nullptr && i->next->idx == val) {
        node *next = i->next->next;
        delete i->next;
        i->next = next;
    }
}

void destroy(node **n)
{
    if ((*n)->next != nullptr) {
        destroy(&((*n)->next));
    }
    delete *n;
    *n = nullptr;
}

int main()
{
    node *n = nullptr;

    add_node(&n, 10);
    add_node(&n, 11);
    add_node(&n, 12);
    add_node(&n, 13);
    add_node(&n, 14);
    add_node(&n, 2);

    remove_node(&n, 10);
    remove_node(&n, 13);
    remove_node(&n, 2);

    destroy(&n);
}