//
// Created by Bartłomiej Grzesik on 10/11/2019.
//


#include <iostream>
#include <cmath>

struct ulamek
{
    int l;
    int m;
};

int nwd(int a, int b)
{
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

ulamek skroc(ulamek u)
{
    int d = nwd(u.l, u.m);

    u.l /= d;
    u.m /= d;

    return u;
}

ulamek dodaj(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.m + b.l * a.m;
    u.m = a.m * b.m;
    return skroc(u);
}

ulamek odejmij(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.m - b.l * a.m;
    u.m = a.m * b.m;
    return skroc(u);
}

ulamek mnoz(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.l;
    u.m = a.m * b.m;
    return u;
}

ulamek dziel(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.m;
    u.m = b.l * a.m;
    return u;
}

ulamek wczytaj()
{
    ulamek u;
    std::cin >> u.l;
    std::cin >> u.m;
    return u;
}

ulamek poteguj(ulamek u, int n)
{
    ulamek a;

    a.l = 1;
    a.m = 1;

    for (int i = 0; i < n; ++i) {
        a.l *= u.l;
        a.m *= u.m;
    }

    return a;
}

int main()
{

}