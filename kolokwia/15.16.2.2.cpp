//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>

const int N = 9;

int count_bits(int a)
{
    int b = a;
    b |= b >> 16;
    b |= b >> 8;
    b |= b >> 4;
    b |= b >> 2;
    b |= b >> 1;

    b ^= b >> 1;

    int c = 0;

    for (; b > 0; b >>= 1) {
        if ((a & b) != 0) {
            c++;
        }
    }

    return c;
}

bool _is_split_possible(int t[N], int idx, int s1, int s2, int s3)
{
    if (idx == N) {
        return s1 == s2 && s2 == s3;
    }

    int i = count_bits(t[idx]);
    return
        _is_split_possible(t, idx + 1, s1 + i, s2, s3)
        ||
        _is_split_possible(t, idx + 1, s1, s2 + i, s3)
        ||
        _is_split_possible(t, idx + 1, s1, s2, s3 + i);

}

bool is_split_possible(int t[N])
{
    return _is_split_possible(t, 0, 0, 0, 0);
}


int main(int argc, char *argv[])
{
    std::cout << count_bits(0b10101010) << std::endl;
    int tab[] = { 2, 3, 5, 7, 11, 13, 16 };
    std::cout << is_split_possible(tab) << std::endl;
}