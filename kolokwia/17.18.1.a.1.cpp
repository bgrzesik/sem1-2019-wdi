//
// Created by Bartłomiej Grzesik on 30/11/2019.
//


#include <iostream>

bool diff(int a, int b, int base)
{
    int digits[16];
    for (int i = 0; i < 16; digits[i++] = 0);

    while (a != 0) {
        digits[a % base]++;
        a /= base;
    }

    while (b != 0) {
        if (digits[b % base] != 0) {
            return false;
        }
        b /= base;
    }

    return true;
}

int findDiffBase(int a, int b)
{
    for (int i = 2; i < 16; ++i) {
        if (diff(a, b, i)) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char *argv[])
{
    std::cout << findDiffBase(123, 522) << std::endl;
}