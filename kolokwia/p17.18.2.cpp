//
// Created by Bartłomiej Grzesik on 02/12/2019.
//

#include <iostream>

const int N = 9;

int max(int a, int b)
{
    return a > b ? a : b;
}

int max4(int a, int b, int c, int d)
{
    return max(max(a, b), max(c, d));
}


int _splits(int t1[N], int t2[N], int n1, int n2, int sum1, int sum2, int idx)
{
    if (idx == N) {
        if (n1 == n2 and sum1 == sum2) {
            return n1;
        }
        return 0;
    }

    return max4(
        _splits(t1, t2, n1 + 1, n2 + 1, sum1 + t1[idx], sum2 + t2[idx], idx + 1),
        _splits(t1, t2, n1 + 1, n2, sum1 + t1[idx], sum2, idx + 1),
        _splits(t1, t2, n1, n2 + 1, sum1, sum2 + t2[idx], idx + 1),
        _splits(t1, t2, n1, n2, sum1, sum2, idx + 1)
    );
}

int split(int t1[N], int t2[N])
{
    return _splits(t1, t2, 0, 0, 0, 0, 0);
}

int main()
{
    int tab1[] = { 1, 2, 3, 1, 5, 2, 2, 2, 6 };
    int tab2[] = { 1, 2, 3, 1, 5, 2, 2, 2, 6 };
    std::cout << split(tab1, tab2);
}