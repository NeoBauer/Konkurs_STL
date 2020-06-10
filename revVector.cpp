#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void printVec (std::vector<int>& vec) {
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main() {
std::vector<int> vector {1, 0, 5, 2, 7};
std::cout << "Original vector: " << '\n';
printVec(vector);
std::vector<int> revVector (5);

std::cout << "Start reversing: " << '\n';
std::copy(vector.crbegin(), vector.crend(), revVector.begin());
printVec(revVector);
std::copy(vector.cbegin(), vector.cend(), revVector.rbegin());
printVec(revVector);

std::copy_backward(vector.crbegin(), vector.crend(), revVector.end());
printVec(revVector);
std::copy_backward(vector.cbegin(), vector.cend(), revVector.rend());
printVec(revVector);

std::copy_if(vector.crbegin(), vector.crend(), revVector.begin(), [](int i){return true;});
printVec(revVector);
std::copy_if(vector.cbegin(), vector.cend(), revVector.rbegin(), [](int i){return true;});
printVec(revVector);

std::copy_n(vector.crbegin(), vector.size(), revVector.begin());
printVec(revVector);
std::copy_n(vector.cbegin(), vector.size(), revVector.rbegin());
printVec(revVector);

std::move(vector.crbegin(), vector.crend(), revVector.begin());
printVec(revVector);
std::move(vector.cbegin(), vector.cend(), revVector.rbegin());
printVec(revVector);

std::move_backward(vector.crbegin(), vector.crend(), revVector.end());
printVec(revVector);
std::move_backward(vector.cbegin(), vector.cend(), revVector.rend());
printVec(revVector);

std::reverse(vector.begin(), vector.end());
std::cout << "Reverse original vector: " << '\n';
printVec(vector);
std::reverse(vector.rbegin(), vector.rend());
std::cout << "Back to original vector: " << '\n';
printVec(vector);

std::reverse_copy(vector.cbegin(), vector.cend(), revVector.begin());
printVec(revVector);
std::reverse_copy(vector.crbegin(), vector.crend(), revVector.rbegin());
printVec(revVector);

std::transform(vector.crbegin(), vector.crend(), revVector.begin(), [](int i){return i;});
printVec(revVector);
std::transform(vector.cbegin(), vector.cend(), revVector.rbegin(), [](int i){return i;});
printVec(revVector);

return 0;
}