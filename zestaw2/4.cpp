//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 4. Liczba dwu-trzy-piątkowa w rozkładzie na czynniki pierwsze nie posiada innych czynników niż 2,3,5.
// Jedynka też jest taką liczbą. Napisz program,
// który wylicza ile takich liczb znajduje się w przedziale od 1 do N włącznie.


int main()
{
    const int n = 102;
    uint l = 0;

    for (uint i2 = 1; i2 <= n; i2 *= 2) {
        for (uint i3 = i2; i3 <= n; i3 *= 3) {
            for (int i5 = i3; i5 <= n; i5 *= 5) {
                l++;
            }
        }
    }
    std::cout << l << std::endl;

}