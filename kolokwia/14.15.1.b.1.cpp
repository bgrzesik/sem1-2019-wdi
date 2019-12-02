//
// Created by Bartłomiej Grzesik on 01/12/2019.
//

#include <iostream>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

//2,3,2,7,1,2,4,8,5,2,2,4,3,9,5,4,0
int main(int argc, const char *argv[])
{
    int ring[5];
    for (int i = 0; i < 5; std::cin >> ring[i++]);

    int i = -1;
    do {
//        printf("[ %d %d %d %d %d ]\n", ring[0], ring[1], ring[2], ring[3], ring[4]);
        for (int j = 0; j < 5; ++j) {
//            printf("%d %d %d %d \t %d\n", ring[(j + 1) % 5], ring[(j + 2) % 5], ring[(j + 3) % 5], ring[(j + 4) % 5], ring[j % 5]);
            if (ring[(j + 1) % 5] + ring[(j + 2) % 5] + ring[(j + 3) % 5] + ring[(j + 4) % 5] == ring[j % 5] * 4) {
                std::cout << ring[j % 5] << std::endl;
            }
        }

        i++;
        i %= 5;
        std::cin >> ring[i];
    } while (ring[i] != 0);

}