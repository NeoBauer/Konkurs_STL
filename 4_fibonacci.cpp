#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
 
constexpr int howManyElements = 10;

std::array<int, howManyElements> fibo {1};

void printFibo (std::array<int, howManyElements> a) {
   std::copy(begin(a), end(a), std::ostream_iterator<int> {std::cout, " "});
}

int main() {
    std::adjacent_difference(begin(fibo), std::prev(end(fibo)), std::next(begin(fibo)), std::plus<> {});
    printFibo(fibo);

    return 0;
}