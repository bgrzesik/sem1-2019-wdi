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

int liczbaPodciagow(int n)
{
    return (n - 2) * (n - 1) / 2;
}

int policzCiagGeo(ulamek *t, int n)
{
    int l = 0;

    for (int i = 0; i < n - 1;) {
        int start = i++;

        ulamek ilo = iloraz(t[i], t[start]);

        while (i < n && taki_sam(iloraz(t[i], t[i - 1]), ilo)) i++;

        l += liczbaPodciagow(i - start);
    }

    return l;
}

int maxCiagAryt(ulamek t[], int n)
{
    int l = 0;

    for (int i = 0; i < n - 1;) {
        int start = i++;

        ulamek r = roznica(t[i], t[start]);

        while (i < n && taki_sam(roznica(t[i], t[i - 1]), r)) i++;

        l += i - start;
    }

    return l;

}

int garekLove(ulamek t[], int n)
{
    int maxGeo = policzCiagGeo(t, n);
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
    std::cout << policzCiagGeo(t, N) << std::endl;
    std::cout << maxCiagAryt(t, N);

}
