//
// Created by Bartłomiej Grzesik on 02/12/2019.
//

#include <iostream>
#include <cmath>

const int N = 8;

#define T true
#define F false

bool t[N][N] {
    { F, F, F, F, F, F, F, F },
    { F, F, F, F, F, F, F, F },
    { F, F, F, F, F, F, F, F },
    { F, F, F, F, F, F, F, F },
    { F, F, F, F, F, F, F, F },
    { F, F, F, F, F, F, F, F },
    { F, F, F, F, F, F, F, F },
    { F, F, F, F, F, F, F, F },
};

int offx[] = { -2, +2, -1, +1 };
int offy[] = { +1, +1, +2, +2 };

int min(int a, int b)
{
    return a < b ? a : b;
}

int count_steps(int x, int y)
{
//    printf("%d, %d\n", x, y);
    if (y == 7) {
        return 0;
    }
    int dist = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        int nx = x + offx[i];
        int ny = y + offy[i];

        if (nx < 0 or ny < 0 or nx >= N or ny >= N) {
            continue;
        }

        if (t[nx][ny]) {
            continue;
        }

        dist = min(dist, 1 + count_steps(nx, ny));
    }

    return dist;
}

int main()
{
    std::cout << count_steps(1, 0) << std::endl;
    std::cout << count_steps(5, 0) << std::endl;
}