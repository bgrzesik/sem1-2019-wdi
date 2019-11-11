//
// Created by Bartłomiej Grzesik on 11/11/2019.
//
#include <iostream>
#include <cmath>
#include "ulamki.hpp"

#define N 10

bool taki_sam(ulamek a, ulamek b)
{
    return a.l == b.l && a.m == b.m;
}

int maxCiagGeo(ulamek t[], int n)
{
    int max = 0;

    for (int i = 0; i < n - 1;) {
        int start = i++;

        ulamek ilo = iloraz(t[i], t[start]);

        while (i < n && taki_sam(iloraz(t[i], t[i - 1]), ilo)) i++;

        if (max < i - start) {
            max = i - start;
            if (i == n) {
                max++;
            }
        }
    }

    return max;
}

int maxCiagAryt(ulamek t[], int n)
{
    int max = 0;

    for (int i = 0; i < n - 1;) {
        int start = i++;

        ulamek r = roznica(t[i], t[start]);

        while (i < n && taki_sam(roznica(t[i], t[i - 1]), r)) i++;

        if (max < i - start) {
            max = i - start;
            if (i == n) {
                max++;
            }
        }
    }

    return max;

}

int garekLove(ulamek t[], int n)
{
    int maxGeo = maxCiagGeo(t, n);
    int maxAryt = maxCiagAryt(t, n);
}

int main()
{
    ulamek t[N] = {

        { 1, 2 },
        { 1, 4 },
        { 1, 8 },
        { 1, 16 },
        { 1, 32 },
        { 1, 2 },
        { 2, 2 },
        { 3, 2 },
        { 4, 2 },
        { 5, 2 },
    };

//    srand(time(0));
//
//    for (int i = 0; i < N; ++i) {
//        ulamek u;
//
//        u.l = rand() % 10 + 1;
//        u.m = rand() % 10 + 1;
//
//        t[i] = u;
//
//        wypisz(u);
//        std::cout << ", ";
//    }

    std::cout << std::endl;
    std::cout << maxCiagGeo(t, N) << std::endl;
    std::cout << maxCiagAryt(t, N);

}
