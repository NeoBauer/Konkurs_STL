#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <iterator>

int main() {
std::vector<int> vec={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


std::cout << "all_of -> ";
std::all_of(vec.begin(), vec.end(), [](int& el){std::cout << el << ", "; return true;});

std::cout << '\n' << "any_of -> ";
std::any_of(vec.begin(), vec.end(), [](int& el){std::cout << el << ", "; return 0;});

std::cout << '\n' << "none_of -> ";
std::none_of(vec.begin(), vec.end(), [](int& el){std::cout << el <<", "; return 0;});

std::cout << '\n' << "for_each -> ";
std::for_each(vec.begin(), vec.end(), [](int& el){std::cout << el <<", ";});

//std::cout << '\n' << "for_each_n -> ";
//std::for_each_n(vec.begin(), std::count(vec), [](int& el){std::cout<<el<<' ';});

std::cout << '\n' << "count_if -> ";
std::count_if(vec.begin(), vec.end(), [](int& el){std::cout << el << ", "; return 0;});

std::cout << '\n' << "mismatch -> ";
std::mismatch(vec.begin(), vec.end(), vec.begin(), vec.end(), [](int& el, int& el2){std::cout << el << ", "; return true ;} );

std::cout << '\n' << "find_if -> ";
std::find_if(vec.begin(), vec.end(), [](int& el){std::cout << el <<", "; return 0;});

std::cout << '\n' << "find_if_not -> ";
std::find_if_not(vec.begin(), vec.end(), [](int& el){std::cout << el <<", "; return 1;});

std::cout << '\n' << "find_end -> ";
std::find_end(vec.rbegin(), vec.rend(), vec.begin(), vec.end(), [](int& el, int& el2){std::cout << el << ", "; return true ;} );

std::cout << '\n' << "search -> ";
std::search(vec.begin(), vec.end(), vec.begin(), vec.end(), [](int& el, int& el2){std::cout << el2 << ", "; return true ;} );

std::cout << '\n' << "copy with output iterator -> ";
std::ostream_iterator<int> out_it (std::cout,", ");
std::copy ( vec.begin(), vec.end(), out_it );

std::cout << '\n' << "copy_if with output iterator -> ";
std::copy_if ( vec.begin(), vec.end(), out_it,[](int& el){return true;} );

std::cout << '\n' << "copy_n with output iterator -> ";
std::copy_n ( vec.begin(), vec.size(), out_it );

std::cout << '\n' << "move with output iterator -> ";
std::move( vec.begin(), vec.end(), out_it );

std::cout << '\n' << "transform -> ";
std::transform ( vec.begin(), vec.end(), out_it, [](int& el ){return el;} );


std::cout << '\n' << "generate -> ";   // WARNING: control may reach end of non-void lambda [-Wreturn-type]
std::vector<int> vec2(vec.size(), 1);
auto it_first = vec.begin();
auto it_last  = vec.end();
std::generate ( vec2.begin(), vec2.end(), [it_first, it_last]()
  mutable {
    if(it_first < it_last){
    std::cout << *it_first << ", ";
    it_first++;
    return *it_first;
    }
 });

}
