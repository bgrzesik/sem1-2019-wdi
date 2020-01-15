//
// Created by Bartłomiej Grzesik on 09/01/2020.
//

#include <iostream>

struct node
{
    int val;
    node *next;
};

bool is_cyclic(node *n)
{
    node *fast = n;
    node *slow = n;

    while (slow != nullptr and fast != nullptr and fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
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
    f.next = &c;

    std::cout << is_cyclic(&a) << std::endl;

}