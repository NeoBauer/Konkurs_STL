#include <algorithm>
#include <iostream>
#include <string>

bool checkIfAnagram(std::string first, std::string second) {
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    return first == second;
}

int main() {
    std::string str1 = "TOmek Ala";
    std::string str2 = "lTa AOkem";
    if (checkIfAnagram(str1, str2)) {
        std::cout << "ANAGRAM\n";
    } else {
        std::cout << "NOT ANAGRAM\n";
    }

    return 0;
}