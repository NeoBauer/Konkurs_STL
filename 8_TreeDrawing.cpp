#include <algorithm>
#include <iostream>
#include <vector>

void printTree(int height){
    if(height < 0){
        std::cout << "Invalid size of tree" << '\n';
    } else {
        std::vector<std::string> tree(height);
        std::generate(tree.begin(), tree.end(), 
            [spaceCount = height - 1,starCount=1] () mutable {
                std::string part1(spaceCount, ' ');
                std::string part2(starCount, '*');
                spaceCount--;
                starCount += 2;
                return part1 + part2;
            });
        std::all_of(tree.begin(), tree.end(), [](auto& el){
            std::cout<<el<<'\n'; return true;
        });
    }
}

int main() {
  printTree(7);
}
