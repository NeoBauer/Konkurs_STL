#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
 
constexpr int howManyElements = 10;

std::array<int, howManyElements> fibo {1};

void printFibo (std::array<int, howManyElements> a) {
   std::copy(begin(a), end(a), std::ostream_iterator<int> {std::cout, " "});
   std::cout << '\n';
}

int getFibFromVector(int fibnum){
  if(fibnum < 0){
    return -1;
  }
  if(fibnum == 0){
    return 0;
  }
  std::vector<int> fibVec(fibnum);
  std::generate(fibVec.begin(), fibVec.end(), 
            [first = 0, second = 1] () mutable {
              int tmp = second;
              second += first;
              first = tmp;
              return first;
            });
    std::all_of(fibVec.begin(), fibVec.end(), [](auto& el){std::cout<<el<<' '; return true;});
    return fibVec.at(fibnum -1);
}

int main() {
    //1
    std::adjacent_difference(begin(fibo), std::prev(end(fibo)), std::next(begin(fibo)), std::plus<> {});
    printFibo(fibo);

    //2
    getFibFromVector(howManyElements);

    return 0;
}