#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

auto removeDuplicates(std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> vecOfSplitStr(std::istream_iterator<std::string>{iss},
                                           std::istream_iterator<std::string>());

    auto idx = std::unique(vecOfSplitStr.begin(), vecOfSplitStr.end());
    vecOfSplitStr.erase(idx, vecOfSplitStr.end());

    std::transform(vecOfSplitStr.begin(), vecOfSplitStr.end(), vecOfSplitStr.begin(), [](std::string s) {
        s.push_back(' ');
        return s;
    });

    return vecOfSplitStr;
}

int main() {
    std::string text = "Ala ma ma kota, a kot ma ma Ale Ale.";
    std::cout << "Original text: " << text << '\n';
    auto result = removeDuplicates(text);
    for (const auto& el : result) {
        std::cout << el;
    }
    return 0;
}
