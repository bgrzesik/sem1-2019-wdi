//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>

// 3. Napisać program sprawdzający czy istnieje spójny podciąg ciągu Fibonacciego o zadanej sumie.

int main() {
    const int dsum = 555;

    int l = 0;
    int n = 1;

    while (n < dsum) {
        int nn = n + l;
        l = n;
        n = nn;
    }

    std::cout << n << std::endl;

    int l2 = 0;
    int n2 = 1;

    while (n - n2 > dsum) {
        int nn = n2 + l2;
        l2 = n2;
        n2 = nn;
    }

    if (n - n2 == dsum) {
        std::cout << "TAK" << std::endl;
    }

    std::cout << n2 << ".." << n << " = " << n - n2 << "(" << dsum << ")"<< std::endl;

}