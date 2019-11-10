//
// Created by Bartłomiej Grzesik on 10/11/2019.
//


#include <iostream>
#include <cmath>

#define N 15

struct hetman
{
    int w;
    int k;
};

struct dane
{
    hetman t[N];
    int n;
};

bool szachuje(hetman a, hetman b)
{
//    if (a.w == b.w && b.k == b.k) {
//        return false;
//    }

    if (a.w == b.w || a.k == b.k) {
        return true;
    }

    return abs(a.w - b.w) == abs(a.k - b.k);
}

dane losowi_hetmani(int n)
{
    dane d;
    d.n = n;

    bool zajete[N][N];

// memset
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            zajete[i][j] = false;
        }
    }

    srand(time(0));

    while (n >= 0) {
        int w = rand() % N;
        int k = rand() % N;

        if (!zajete[w][k]) {
            zajete[w][k] = true;
            n--;

            hetman h;
            h.w = w;
            h.k = k;

            d.t[n] = h;
        }
    }

    return d;
}

void wypisz_hemanow(dane d)
{

    bool zajete[N][N];

    // memset
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            zajete[i][j] = false;
        }
    }

    for (int i = 0; i < d.n; ++i) {
        hetman h = d.t[i];
        zajete[h.w][h.k] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << (zajete[i][j] ? "H|" : "_|");
        }
        std::cout << std::endl;
    }

}

int main()
{
    dane d = losowi_hetmani(N);
    wypisz_hemanow(d);

    bool tab[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tab[i][j] = false;
        }
    }

    for (int i = 0; i < d.n; ++i) {
        hetman a = d.t[i];

        for (int j = i + 1; j < d.n; ++j) {
            hetman b = d.t[j];

            if (szachuje(a, b)) {
                tab[a.w][a.k] = true;
                tab[b.w][b.k] = true;
            }
        }
    }

    std::cout << std::endl << std::endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << (tab[i][j] ? "H|" : "_|");
        }
        std::cout << std::endl;
    }
}