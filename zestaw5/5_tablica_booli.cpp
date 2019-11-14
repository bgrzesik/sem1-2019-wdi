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

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// p0 ========== p2
// ||    p?      ||
// ||            ||
// p1 ========== p3
bool istnieje(dane dane)
{
    bool przesten[32][32];

    for (int w = 0; w < 32; ++w) {
        for (int k = 0; k < 32; ++k) {
            przesten[w][k] = false;
        }
    }

    for (int i = 0; i < dane.n; ++i) {
        punkt p = dane.t[i];
        przesten[p.x][p.y] = true;
    }

    for (int i = 0; i < dane.n; ++i) {
        punkt p0 = dane.t[i];

        for (int j = i + 1; j < dane.n; ++j) {
            punkt p1 = dane.t[j];

            if (p0.x != p1.x) {
                continue;
            }

            int a = abs(p0.y - p1.y);

            bool found = false;
            if (p0.x + a < 32 && przesten[p0.x + a][p0.y] && przesten[p0.x - a][p1.y]) {
                found = true;
                for (int x = p0.x; x < p0.x + a; ++x) {
                    for (int y = min(p0.y, p1.y); y < max(p0.y, p1.y); ++y) {
                        found &= !przesten[x][y];

                        if (!found) {
                            break;
                        }
                    }
                }
            }

            if (p0.x - a >= 0 && przesten[p0.x - a][p0.y] && przesten[p0.x - a][p1.y]) {
                found = true;
                for (int x = p0.x - a; x < p0.x; ++x) {
                    for (int y = min(p0.y, p1.y); y < max(p0.y, p1.y); ++y) {
                        found &= !przesten[x][y];

                        if (!found) {
                            break;
                        }
                    }
                }
            }

            if (found) {
                return true;
            }
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

