//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>


int main(int argc, char *argv[])
{
    double in = 52;

    double a = 1;
    double b = 2;
    int i = 1;

    while (in > a and in > b) {
        i++;
        b = b + a;
        if (a < in and b > in) {
            std::cout << "b " << i << std::endl;
            break;
        }

        a = a + b / 3.0;

        if (a > in and b > in) {
            std::cout << "a " << i << std::endl;
            break;
        }
    }
}