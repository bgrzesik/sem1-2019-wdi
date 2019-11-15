//
// Created by Bartłomiej Grzesik on 2019-05-10.
//

#include <algorithm>
#include <vector>
#include <tuple>
#include <future>
#include <functional>
#include <utility>
#include <variant>
#include <optional>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <random>
#include <complex>
#include <memory>
#include <numeric>
#include <atomic>
#include <ranges>

namespace fs = std::filesystem;


auto lol() -> int
{
    return 1;
}

int main(int argc, const char *argv[])
{
    using Variant = std::variant<int, double, std::string>;

    const std::vector<Variant> vars = {
        lol(),
        1.05,
        "LOL",
        100,
        42.42,
    };

    auto v = new auto(1);
    delete v;

    auto[a, b, c] = std::make_tuple(1, 2, 3);
    std::cout << " " << a << " " << b << " " << c << std::endl << std::flush;


    for (const auto &path : fs::directory_iterator(fs::current_path())) {
        std::cout << path.path() << std::endl << std::flush;
    }

    std::random_device rd;
    std::cout << rd() << std::endl << std::flush;

    std::vector<int> nums(10);
    std::generate(nums.begin(), nums.end(), [ &rd ]() { return std::abs(int(rd())); });

    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, "."));


    std::vector<int> perm(5);
    std::iota(perm.begin(), perm.end(), 0);

    auto filename = fs::current_path().append("permutations.txt");
    std::fstream out;
    out.open(filename, std::ios::out);

    int sum = 0;
    do {
        std::copy(perm.begin(), perm.end(), std::ostream_iterator<int>(out, "\t"));
        out << std::endl;

        const auto &[a0, a1, a2, a3, a4] = std::make_tuple(perm[0], perm[1], perm[2], perm[3], perm[4]);
        sum += a0 * 10000 + a1 * 1000 + a2 * 100 + a3 * 10 + a4;
    } while (std::next_permutation(perm.begin(), perm.end()));


    std::fill_n(std::ostream_iterator<const char *>(std::cout), 3, "\n");
    std::cout << sum << std::endl << std::flush;
    std::fill_n(std::ostream_iterator<const char *>(std::cout), 3, "\n");

    perm.resize(1000);
    std::iota(perm.begin(), perm.end(), 0);
    std::copy_if(perm.begin(), perm.end(), std::ostream_iterator<int>(std::cout, "\n"),
                 [](auto &e) { return e % 100 == 0; });

    std::fill_n(std::ostream_iterator<const char *>(std::cout), 3, "\n");

    std::vector<int> filtered;
    std::copy_if(perm.begin(), perm.end(), std::back_inserter(filtered), [](auto &e) { return e % 50 == 0; });
    std::copy(filtered.begin(), filtered.end(), std::ostream_iterator<int>(std::cout, "\n"));


    std::vector<char> chars;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis('A', 'Z');
    std::uniform_int_distribution<> dis2('a', 'z');
    std::generate_n(std::back_inserter(chars), 50, std::bind(dis, std::ref(mt)));
    std::generate_n(std::back_inserter(chars), 50, std::bind(dis2, std::ref(mt)));
    std::shuffle(chars.begin(), chars.end(), mt);
    std::copy(chars.begin(), chars.end(), std::ostream_iterator<char>(std::cout));

    std::fill_n(std::ostream_iterator<const char *>(std::cout), 3, "\n");

    std::string text = "let me see you striped";
    std::for_each(text.begin(), text.end(), [](auto &e) {
        if (e >= 'a' && e <= 'z') {
            e = 'a' + ((e - 'a' + 5 + ('z' - 'a')) % ('z' - 'a'));
        } else if (e >= 'A' && e <= 'Z') {
            e = 'A' + ((e - 'A' + 5 + ('z' - 'a')) % ('Z' - 'A'));
        }
    });
    std::cout << text << std::endl << std::flush;
    std::for_each(text.begin(), text.end(), [](auto &e) {
        if (e >= 'a' && e <= 'z') {
            e = 'a' + ((e - 'a' - 5 + ('z' - 'a')) % ('z' - 'a'));
        } else if (e >= 'A' && e <= 'Z') {
            e = 'A' + ((e - 'A' - 5 + ('z' - 'a')) % ('Z' - 'A'));
        }
    });
    std::cout << text << std::endl << std::flush;


}
