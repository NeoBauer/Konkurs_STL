#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

static int palindromCnt = 0;
static int notPalindromCnt = 0;

void PrepareString(std::string& text) {
    auto deleteSpecialChars = [](char& c) {
        c = std::tolower(c);
        return std::isspace(c) || std::ispunct(c);
    };

    text.erase(std::remove_if(text.begin(), text.end(), deleteSpecialChars), text.end());
}

bool CheckResult(std::string& text, std::string& revText) {
    if (revText == text) {
        palindromCnt++;
        return true;
    } else {
        notPalindromCnt++;
        return false;
    }
}

void PrintResult() {
    std::cout << '\n'
              << "Find palindrom num:" << palindromCnt;
    std::cout << '\n'
              << "No find palindrom num: " << notPalindromCnt << '\n';

    if (palindromCnt > 0 && notPalindromCnt == 0) {
        std::cout << "\n *** Input text is palindrom ***";
    } else {
        std::cout << "\n *** Input text isn't palindrom *** \n";
    }
}

bool isPalindromWithCopy(std::string& text) {
    std::string revText;
    revText.resize(text.size());

    std::copy(text.rbegin(), text.rend(), revText.begin());
    return CheckResult(text, revText);
}

bool isPalindromWithCopyIf(std::string& text) {
    std::string revText;
    revText.resize(text.size());

    std::copy_if(text.rbegin(), text.rend(), revText.begin(), [](char c) { return true; });
    return CheckResult(text, revText);
}

bool isPalindromWithCopyN(std::string& text) {
    std::string revText;
    revText.resize(text.size());

    std::copy_n(text.rbegin(), text.size(), revText.begin());

    return CheckResult(text, revText);
}

bool isPalindromWithRevCopy(std::string& text) {
    std::string revText;
    revText.resize(text.size());

    std::reverse_copy(text.begin(), text.end(), revText.begin());
    return CheckResult(text, revText);
}

bool isPalindromWithRev(std::string& text) {
    std::string revText;
    revText.resize(text.size());
    revText = text;

    std::reverse(revText.begin(), revText.end());
    return CheckResult(text, revText);
}

bool isPalindromWithMismatch(std::string& text) {
    auto missIt = std::mismatch(text.begin(), text.end(), text.rbegin(), text.rend());
    if (missIt.first == text.end()) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithStringConstructor(std::string& text) {
    std::string revText;
    revText.resize(text.size());
    revText = std::string(text.rbegin(), text.rend());
    return CheckResult(text, revText);
}

bool isPalindromWithForEach(std::string& text) {
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

    return CheckResult(firstHalf, secondHalf);
}

bool isPalindromWithCountIf(std::string& text) {
    size_t index = 0;
    int correctCharsNum = std::count_if(text.begin(), std::next(text.begin(), text.size() / 2),
                                        [&](char c) {
                                            return text[text.size() - 1 - index++] == c;
                                        });
    if (correctCharsNum == static_cast<int>(text.size() / 2)) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithFindIfNot(std::string& text) {
    size_t index = 0;
    auto findIt = std::find_if_not(text.begin(), std::next(text.begin(), text.size() / 2),
                                   [&](char c) {
                                       return text[text.size() - 1 - index++] == c;
                                   });
    if (findIt == std::next(text.begin(), text.size() / 2)) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithEqual(std::string& text) {
    bool result = std::equal(text.begin(), std::next(text.begin(), text.size() / 2),
                             text.rbegin(), std::next(text.rbegin(), text.size() / 2));

    if (result) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithMove(std::string text) {
    std::string revText;
    std::string firstHalf;
    firstHalf.resize(text.size() / 2);
    revText.resize(text.size() / 2);
    std::move(text.rbegin(), std::next(text.rbegin(), text.size() / 2),
              revText.begin());
    firstHalf = text.substr(0, text.size() / 2);
    return CheckResult(firstHalf, revText);
}

bool isPalindromWithRemoveIf(std::string& text) {
    std::string revText;
    revText.resize(text.size());
    size_t index = 0;
    revText = text;
    revText.erase(std::remove_if(revText.begin(),
                                 std::next(revText.begin(), revText.size() / 2),
                                 [&](char c) { return text[text.size() - 1 - index++] != c; }),
                  revText.end());

    if (revText.size() != text.size() / 2) {
        notPalindromCnt++;
        return false;
    }

    palindromCnt++;
    return true;
}

bool isPalindromWithReplaceIf(std::string text) {
    char magic = '!';
    size_t index = text.size() - 1;
    std::replace_if(
        text.begin(), std::next(text.begin(), text.size() / 2),
        [&](char c) {
            return c != text[index--];
        },
        magic);
    auto pos = text.find(magic);

    if (pos != text.npos) {
        notPalindromCnt++;
        return false;
    }

    palindromCnt++;
    return true;
}

bool isPalindromWithSwap(std::string& text) {
    std::string revText = text;
    int j = revText.size() - 1;
    for (size_t i = 0; i < revText.size() / 2; i++, j--) {
        std::swap(revText[i], revText[j]);
    }

    return CheckResult(text, revText);
}

bool isPalindromWithIterSwap(std::string& text) {
    std::string revText = text;
    auto rIt = revText.rbegin();
    auto it = revText.begin();
    std::for_each(revText.begin(), std::next(revText.begin(), revText.size() / 2),
                  [&](char c) mutable {
                      std::iter_swap(it++, rIt++);
                  });

    return CheckResult(text, revText);
}

bool isPalindromWithRotate(std::string text) {
    std::rotate(text.begin(), std::next(text.begin(), text.size() / 2), text.end());

    auto startIt = text.begin();
    if (text.size() % 2 == 1 && text.size() > 1)
        startIt++;

    bool result = std::equal(startIt, std::next(startIt, text.size() / 2), text.rbegin());

    if (result) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithAllOf(std::string& text) {
    size_t index = text.size() - 1;
    bool result = std::all_of(text.begin(), std::next(text.begin(), text.size() / 2),
                              [&](char c) { return c == text[index--]; });

    if (result) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithAnyOf(std::string& text) {
    size_t index = text.size() - 1;
    bool result = std::any_of(text.begin(), std::next(text.begin(), text.size() / 2),
                              [&](char c) { return c != text[index--]; });

    if (!result) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithNoneOf(std::string& text) {
    size_t index = text.size() - 1;
    bool result = std::none_of(text.begin(), std::next(text.begin(), text.size() / 2),
                               [&](char c) { return c != text[index--]; });

    if (result) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

bool isPalindromWithTransform(std::string& text) {
    std::string revText;

    std::transform(text.rbegin(), text.rend(), std::back_inserter(revText),
                   [](char c) { return c; });

    return CheckResult(text, revText);
}

bool isPalindromWithForeachN(std::string& text) {
    int index = text.size() - 1;
    int result = true;
    std::for_each_n(text.begin(), text.size() / 2,
                    [&](char c) {
                        if (c != text[index--]) {
                                result = false;
                            } });

    if (result) {
        palindromCnt++;
        return true;
    }

    notPalindromCnt++;
    return false;
}

int main() {
    std::string text = "Elu, becz - cebule!";  // is palindrome
    //text = "abc";                               // isn't palindrome
    PrepareString(text);

    isPalindromWithCopy(text);
    isPalindromWithCopyIf(text);
    isPalindromWithCopyN(text);
    isPalindromWithRevCopy(text);
    isPalindromWithRev(text);
    isPalindromWithMismatch(text);
    isPalindromWithStringConstructor(text);
    isPalindromWithForEach(text);
    isPalindromWithCountIf(text);
    isPalindromWithFindIfNot(text);
    isPalindromWithEqual(text);
    isPalindromWithMove(text);
    isPalindromWithRemoveIf(text);
    isPalindromWithReplaceIf(text);
    isPalindromWithSwap(text);
    isPalindromWithIterSwap(text);
    isPalindromWithRotate(text);
    isPalindromWithAllOf(text);
    isPalindromWithAnyOf(text);
    isPalindromWithNoneOf(text);
    isPalindromWithTransform(text);
    isPalindromWithForeachN(text);

    PrintResult();

    return 0;
}
