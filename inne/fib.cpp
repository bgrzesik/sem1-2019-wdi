#include <iostream>
#include <cmath>
//
// Created by Bartłomiej Grzesik on 10/10/2019.
//

int main(int argc, const char *argv[])
{
    int n = 1;
    int l = 0;

    for (int i = 0; i < 10; ++i) {
        std::cout << n << std::endl;
        int t = n + l;
        l = n;
        n = t;
    }
}