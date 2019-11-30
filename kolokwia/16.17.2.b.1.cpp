//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>

const int N = 4;

bool _is_prime(int a)
{
    for (int i = 2; i <= sqrt(a); ++i) {
        if ((a % i) == 0) {
            return false;
        }
    }
    return true;
}

int _gen_sums(int t1[N], int t2[N], int idx, bool n1[N], bool n2[N], int sum)
{
    if (idx == 2 * N) {
        bool empty = false;

        for (int i = 0; i < N && !empty; empty |= n1[i++]);
        if (!empty) return 0;

        empty = false;

        for (int i = 0; i < N && !empty; empty |= n2[i++]);
        if (!empty) return 0;

        if (_is_prime(sum)) {
            for (int i = 0; i < N; ++i) {
                if (n1[i]) {
                    std::cout << t1[i] << "+";
                }
            }

            int i = 0;
            for (; i < N && !n2[i]; ++i);
            std::cout << t2[i];

            for (i++; i < N; ++i) {
                if (n2[i]) {
                    std::cout << "+" << t2[i];
                }
            }

            std::cout << std::endl;

            return 1;
        }
        return 0;
    }

    if (idx < N) {
        n1[idx] = true;
        int a = _gen_sums(t1, t2, idx + 1, n1, n2, sum + t1[idx]);
        n1[idx] = false;

        return a + _gen_sums(t1, t2, idx + 1, n1, n2, sum);
    } else {
        n2[idx - N] = true;
        int a = _gen_sums(t1, t2, idx + 1, n1, n2, sum + t2[idx - N]);
        n2[idx - N] = false;

        return a + _gen_sums(t1, t2, idx + 1, n1, n2, sum);
    }
}

int genSums(int t1[N], int t2[N])
{
    bool n1[N];
    bool n2[N];

    for (int i = 0; i < N; n1[i] = n2[i] = false, i++);

    return _gen_sums(t1, t2, 0, n1, n2, 0);
}

int main(int argc, char *argv[])
{
    int t1[] = { 1, 3, 2, 4 };
    int t2[] = { 9, 7, 4, 8 };

    std::cout << genSums(t1, t2) << std::endl;
}