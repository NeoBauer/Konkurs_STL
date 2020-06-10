#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

static int palindromCnt = 0;
static int notPalindromCnt = 0;

void PrepareString(std::string& text) {
    std::cout << "Prepare string" << '\n';

    auto deleteSpecialChars = [](char& c) {
        c = std::tolower(c);
        return std::isspace(c) || std::ispunct(c);
    };

    text.erase(std::remove_if(text.begin(), text.end(), deleteSpecialChars), text.end());
}

void CheckResult(std::string& text, std::string& revText) {
    if (revText == text)
        palindromCnt++;
    else
        notPalindromCnt++;

    revText.clear();
    revText.resize(text.size());
}

void PrintResult() {
    std::cout << '\n'
              << "Find palindrom num:" << palindromCnt;
    std::cout << '\n'
              << "No find palindrom num: " << notPalindromCnt << '\n';
}

bool isPalindrom(std::string& text) {
    std::string revText;
    revText.resize(text.size());

    // first solution
    std::copy(text.rbegin(), text.rend(), revText.begin());
    CheckResult(text, revText);

    // second solution
    std::copy_if(text.rbegin(), text.rend(), revText.begin(), [](char c) { return true; });
    CheckResult(text, revText);

    // third solution
    std::reverse_copy(text.begin(), text.end(), revText.begin());
    CheckResult(text, revText);

    // fourth solution
    revText = text;
    std::reverse(revText.begin(), revText.end());
    CheckResult(text, revText);

    //fifth solution
    auto missIt = std::mismatch(text.begin(), text.end(), text.rbegin(), text.rend());
    if (missIt.first == text.end())
        palindromCnt++;
    else
        notPalindromCnt++;

    //sixth solution
    revText = std::string(text.rbegin(), text.rend());
    CheckResult(text, revText);

    //seventh solution
    std::string firstHalf;
    std::string secondHalf;
    firstHalf.resize(text.size() / 2);
    secondHalf.resize(text.size() / 2);
    size_t index = 0;
    std::for_each(text.begin(), std::next(text.begin(), text.size() / 2),
                  [&](char c) mutable {
                      firstHalf[index] = c;
                      secondHalf[index] = text[text.size() - 1 - index];
                      index++;
                  });
    CheckResult(firstHalf, secondHalf);

    //eigth solution
    index = 0;
    int correctCharsNum = std::count_if(text.begin(), std::next(text.begin(), text.size() / 2),
                                        [&](char c) {
                                            return text[text.size() - 1 - index++] == c;
                                        });
    if (correctCharsNum == text.size() / 2)
        palindromCnt++;
    else
        notPalindromCnt++;

    //ninth solution
    index = 0;
    auto findIt = std::find_if_not(text.begin(), std::next(text.begin(), text.size() / 2),
                                   [&](char c) {
                                       return text[text.size() - 1 - index++] == c;
                                   });
    if (findIt == std::next(text.begin(), text.size() / 2))
        palindromCnt++;
    else
        notPalindromCnt++;

    //tenth solution
    bool result = std::equal(text.begin(), std::next(text.begin(), text.size() / 2),
                             text.rbegin(), std::next(text.rbegin(), text.size() / 2));

    if (result)
        palindromCnt++;
    else
        notPalindromCnt++;

    //eleventh solution
    std::string textCopy;  // must stored original text string for next solutions
    textCopy.resize(text.size());
    std::copy(text.begin(), text.end(), textCopy.begin());
    revText.resize(textCopy.size() / 2);
    std::move(textCopy.rbegin(), std::next(textCopy.rbegin(), textCopy.size() / 2),
              revText.begin());
    firstHalf = textCopy.substr(0, textCopy.size() / 2);
    CheckResult(firstHalf, revText);

    //twelfth solution
    index = 0;
    revText = text;
    revText.erase(std::remove_if(revText.begin(),
                                 std::next(revText.begin(), revText.size() / 2),
                                 [&](char c) { return text[text.size() - 1 - index++] != c; }),
                  revText.end());

    if (revText.size() != text.size() / 2)
        notPalindromCnt++;
    else
        palindromCnt++;

    PrintResult();

    if (palindromCnt > 0 && notPalindromCnt == 0)
        return true;

    return false;
}

int main() {
    std::string text = "Elu, becz - cebule!";
    PrepareString(text);

    if (isPalindrom(text)) {
        std::cout << "TRUE";
    } else {
        std::cout << "FALSE";
    }

    return 0;
}