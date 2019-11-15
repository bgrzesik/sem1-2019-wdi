//
// Created by Bartłomiej Grzesik on 2019-02-05.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

std::string ToBin(int a)
{
    std::string bin = "";
    while (a != 0) {
        bin = (a & 0x01 ? "1" : "0") + bin;
        a >>= 1;
    }
    return bin;
}

int FromBin(const std::string &bin)
{
    int a = 0;
    for (int i = 0; i < bin.length(); ++i) {
        a <<= 1;
        a |= bin.at(i) == '1' ? 1 : 0;
    }
    return a;
}

std::string ToOct(int a)
{
    std::string oct = "";
    while (a != 0) {
        oct = ((char) ('0' + (a & 0x07))) + oct;
        a >>= 3;
    }
    return oct;
}

int FromOct(const std::string &oct)
{
    int a = 0;
    for (int i = 0; i < oct.length(); ++i) {
        a <<= 3;
        a |= ((int) (oct.at(i) - '0')) & 0x07;
    }
    return a;
}

std::string ToHex(int a)
{
    std::string hex = "";
    while (a != 0) {
        int b = a & 0xf;
        if (b < 0xa) {
            hex = (char) ('0' + b) + hex;
        } else {
            hex = (char) ('a' + (b - 0xa)) + hex;
        }
        a >>= 4;
    }
    return hex;
}

int FromHex(const std::string &hex)
{
    int a = 0;
    for (int i = 0; i < hex.length(); ++i) {
        a <<= 4;

        if (hex.at(i) >= 'a' && hex.at(i) <= 'f') {
            a |= 0xa + ((int) (hex.at(i) - 'a')) & 0x0f;
        } else if (hex.at(i) >= 'A' && hex.at(i) <= 'F') {
            a |= 0xa + ((int) (hex.at(i) - 'A')) & 0x0f;
        } else {
            a |= ((int) (hex.at(i) - '0')) & 0x0f;
        }
    }
    return a;
}

int main(int argc, char **argv)
{
    std::cout << "10 dec = " << ToBin(10) << " bin" << std::flush << std::endl;
    std::cout << "11 dec = " << ToBin(11) << " bin" << std::flush << std::endl;

    std::cout << std::flush << std::endl;

    std::cout << "1010 bin = " << FromBin("1010") << "dec" << std::flush << std::endl;
    std::cout << "1011 bin = " << FromBin("1011") << "dec" << std::flush << std::endl;

    std::cout << std::flush << std::endl;

    std::cout << "10 dec = " << ToOct(10) << " oct" << std::flush << std::endl;
    std::cout << "11 dec = " << ToOct(11) << " oct" << std::flush << std::endl;

    std::cout << std::flush << std::endl;

    std::cout << "12 oct = " << FromOct("12") << " dec" << std::flush << std::endl;
    std::cout << "13 oct = " << FromOct("13") << " dec" << std::flush << std::endl;

    std::cout << std::flush << std::endl;

    std::cout << "10 dec = " << ToHex(10) << " hex" << std::flush << std::endl;
    std::cout << "11 dec = " << ToHex(11) << " hex" << std::flush << std::endl;
    std::cout << "20 dec = " << ToHex(20) << " hex" << std::flush << std::endl;
    std::cout << "21 dec = " << ToHex(21) << " hex" << std::flush << std::endl;

    std::cout << std::flush << std::endl;

    std::cout << "a hex = " << FromHex("a") << " dec" << std::flush << std::endl;
    std::cout << "b hex = " << FromHex("b") << " dec" << std::flush << std::endl;
    std::cout << "14 hex = " << FromHex("14") << " dec" << std::flush << std::endl;
    std::cout << "15 hex = " << FromHex("15") << " dec" << std::flush << std::endl;

    std::cout << std::flush << std::endl;
}