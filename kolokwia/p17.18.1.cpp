//
// Created by Bartłomiej Grzesik on 02/12/2019.
//

#include <iostream>

const int N = 9;

int _splits(int *tab, int idx, int dsum, int splits);

int split(int tab[N])
{
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += tab[i];
        int a = _splits(tab, i + 1, sum, 1);
        if (a != 0) {
            return a;
        }
    }
    return 0;
}

int _splits(int *tab, int idx, int dsum, int splits)
{
    if (idx == N) {
        return splits - 1;
    }

    int sum = 0;
    for (int i = idx; i < N; ++i) {
        sum += tab[i];
        if (sum == dsum) {
            return _splits(tab, i + 1, dsum, splits + 1);
        }
    }

    if (sum == dsum) {
        return splits;
    }

    return 0;
}

int main()
{
    int tab[] = { 1, 2, 3, 1, 5, 2, 2, 2, 6 };
    std::cout << split(tab);
}