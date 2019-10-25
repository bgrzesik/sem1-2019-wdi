//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

int main()
{
    const int b = 10;
    int n = 0xcafe;

    std::string str = "";

    while (n > 0) {
        int r = n % b;

        if (r < 10) {
            str += char('0' + r);
        } else {
            str += char('A' + r - 10);
        }

        n /= b;
    }

    for (int i = str.length() - 1; i >= 0; --i) {
        std::cout << str[i];
    }

}