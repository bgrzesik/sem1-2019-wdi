//
// Created by Bartłomiej Grzesik on 11/11/2019.
//
#include <iostream>
#include <cmath>

struct punkt
{
    int x, y;
};

struct dane
{
    punkt t[100];
    int n;
};

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}


// p0 ========== *
// ||    p?      ||
// ||            ||
//  * ========== p3
bool phase4(dane d, punkt p0, punkt p3)
{
    punkt pmin;
    pmin.x = min(p0.x, p3.x);
    pmin.y = min(p0.y, p3.y);

    punkt pmax;
    pmax.x = max(p0.x, p3.x);
    pmax.y = max(p0.y, p3.y);

    for (int i = 0; i < d.n; ++i) {
        punkt p = d.t[i];

        if (p0.x == p.x && p0.y == p.y)
            continue;
        if (p0.x == p.x && p3.y == p.y)
            continue;
        if (p3.x == p.x && p0.y == p.y)
            continue;
        if (p3.x == p.x && p3.y == p.y)
            continue;


        if (pmin.x <= p.x && p.x <= pmax.x &&
            pmin.y <= p.y && p.y <= pmax.y) {
            return false;
        }
    }
    return true;
}

// p0 ========== p1
// ||            ||
// ||            ||
// p2 ========== p3
bool phase3(dane d, punkt p0, punkt p1, punkt p2)
{
    for (int i = 0; i < d.n; ++i) {
        if (d.t[i].x == p0.x && d.t[i].y == p0.y) {
            continue;
        }
        if (d.t[i].x == p1.x && d.t[i].y == p2.y) {
            return phase4(d, p0, d.t[i]);
        }
    }

    return false;
}

// p0 ========== p1
// ||
// ||
// p2
bool phase2(dane d, punkt p0, punkt p1)
{
    for (int i = 0; i < d.n; ++i) {
        if (d.t[i].x == p0.x && d.t[i].y == p0.y) {
            continue;
        }
        if (abs(p0.x - p1.x) == abs(d.t[i].y - p0.y) && phase3(d, p0, p1, d.t[i])) {
            return true;
        }
    }

    return false;
}

// p0 ========== p1
bool phase1(dane d, punkt p0)
{
    for (int i = 0; i < d.n; ++i) {
        if (d.t[i].x == p0.x && d.t[i].y == p0.y) {
            continue;
        }
        if (d.t[i].y == p0.y && phase2(d, p0, d.t[i])) {
            return true;
        }
    }
    return false;
}

bool istnieje(dane d)
{
    for (int i = 0; i < d.n; ++i) {
        if (phase1(d, d.t[i])) {
            return true;
        }
    }
    return false;
}

int main()
{
    dane d;
    d.t[0] = { 1, 0 };
    d.t[1] = { 4, 0 };
    d.t[2] = { 1, 3 };
    d.t[3] = { 4, 3 };
    d.t[4] = { 2, 2 };
    d.n = 5;

    std::cout << istnieje(d) << std::endl;
}
