//
// Created by Bartłomiej Grzesik on 01/12/2019.
//

#include <iostream>

int main(int argc, const char *argv[])
{
    int max[10];
    for (int i = 0; i < 10; max[i++] = INT_MIN);

    int a;
    std::cin >> a;
    max[9] = a;

    while (a != 0) {
        std::cin >> a;
        if (a == 0) {
            break;
        }

        int x = a;
        for (int i = 9; i >= 0; --i) {
            if (max[i] > a) {
                continue;
            }
            if (max[i] <= a) {
                int b = a;
                a = max[i];
                max[i] = b;
            }
        }

    }

    std::cout << max[0] << std::endl;

}