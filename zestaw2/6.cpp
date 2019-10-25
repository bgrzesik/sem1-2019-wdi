//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 6. Dana jest liczba naturalna o niepowtarzających się cyfrach pośród których nie ma zera.
// Ile różnych liczb podzielnych np. przez 7 można otrzymać poprzez wykreślenie dowolnych
// cyfr w tej liczbie. Np. dla 2315 będą to 21, 35, 231, 315.

int CombineCheck(int a, int l)
{
    if (l <= 0) {
        if (a % 7 == 0 && a != 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int with = CombineCheck(a, l / 10);
    a = (a / (l * 10)) * l + a % l;
    return with + CombineCheck(a, l / 10);
}

int main()
{
    const int n = 2315;
    int n_digit = std::pow(10, std::floor(std::log10(n)));
    int result = CombineCheck(n, n_digit);

    std::cout << result << std::endl;
}