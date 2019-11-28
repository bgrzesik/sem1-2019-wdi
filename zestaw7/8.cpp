//
// Created by Bartłomiej Grzesik on 28/11/2019.
//

#include <cstdio>

int t[8][8] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    1, 2, 3, 4, 5, 6, 7, 8,
    1, 2, 3, 4, 5, 6, 7, 8,
    1, 2, 3, 4, 5, 6, 7, 8,

    1, 2, 3, 4, 5, 6, 7, 8,
    1, 2, 3, 4, 5, 6, 7, 8,
    1, 2, 3, 4, 5, 6, 7, 8,
    1, 2, 3, 4, 5, 6, 7, 8,
};

void recur(int x, int y, int cost, int step, int smallest[7], int current[7], int *s_cost)
{
    if (x < 0 || x > 7) {
        return;
    }

    cost += t[y][x];

    if (step == 0) {
        if (*s_cost > cost && x == 7 && y == 7) {
            for (int i = 0; i < 7; ++i) {
                smallest[i] = current[i];
                *s_cost = cost;
            }
        }
        return;
    }

    current[y] = x + 1;
    recur(x + 1, y + 1, cost, step - 1, smallest, current, s_cost);

    current[y] = x;
    recur(x, y + 1, cost, step - 1, smallest, current, s_cost);

    current[y] = x - 1;
    recur(x - 1, y + 1, cost, step - 1, smallest, current, s_cost);
}

void cheaper(int x)
{
    int smallest[7];
    int s_cost = 0x7fffffff;

    int current[7];


    recur(x, 0, 0, 7, smallest, current, &s_cost);

    printf("(%d, %d)\n", x, 0);
    for (int i = 0; i < 7; ++i) {
        printf("(%d, %d)\n", smallest[i], i + 1);
    }
}

int main(int argc)
{
    cheaper(7);
}