#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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

    std::string resultString;
    return accumulate(begin(vecOfSplitStr), end(vecOfSplitStr), resultString);
}

int main() {
    std::string text = "Ala ma ma kota, a kot ma ma Ale Ale.";
    std::cout << "Original text: " << text << '\n';
    std::cout << removeDuplicates(text);
    return 0;
}
