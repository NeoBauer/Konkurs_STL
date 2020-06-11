#include <algorithm>
#include <iostream>
#include <string>

void PrepareString(std::string& text) {
    auto deleteSpecialChars = [](char& c) {
        c = std::tolower(c);
        return std::isspace(c) || std::ispunct(c);
    };

    text.erase(std::remove_if(text.begin(), text.end(), deleteSpecialChars), text.end());
}

bool checkIfAnagram(std::string first, std::string second) {
    PrepareString(first);
    PrepareString(second);

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    return first == second;
}

int main() {
    std::string str1 = "Tomek";
    std::string str2 = "TomekG";
    if (checkIfAnagram(str1, str2)) {
        std::cout << "ANAGRAM\n";
    } else {
        std::cout << "NOT ANAGRAM\n";
    }

    return 0;
}