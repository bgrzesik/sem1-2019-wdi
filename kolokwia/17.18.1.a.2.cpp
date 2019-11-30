//
// Created by Bartłomiej Grzesik on 30/11/2019.
//


#include <iostream>

const int N = 14;
int tab[N];

int findSeq(int t[N])
{
    int len = 0;

    for (int start = 0; start < N; ++start) {
        int sumIdx = 0;
        int sumElem = 0;

        int cLen = 1;
        int lastElem = t[start];

        for (int i = start + 1; i < N; ++i) {
            if (lastElem >= t[i]) {
                continue;
            }

            cLen++;
            sumIdx += i;
            sumElem += t[i];

            lastElem = t[i];

            if (sumIdx != 0 and sumElem == sumIdx and len < cLen) {
                len = cLen;
            }
        }
    }

    return len;
}

int main(int argc, const char *argv[])
{
    int vals[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 2, 3, 4 };
    std::cout << findSeq(vals) << std::endl;
}