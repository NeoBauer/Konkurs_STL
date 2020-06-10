#include <algorithm>
#include <numeric>
#include <vector>


std::copy(vector.crbegin(), vector.crend(), revVector.begin());
std::copy(vector.cbegin(), vector.cend(), revVector.rbegin());

std::copy_backward(vector.crbegin(), vector.crend(), revVector.end());
std::copy_backward(vector.cbegin(), vector.cend(), revVector.rend());

std::copy_if(vector.crbegin(), vector.crend(), revVector.begin(), [](int i){return true;});
std::copy_if(vector.cbegin(), vector.cend(), revVector.rbegin(), [](int i){return true;});

std::copy_n(vector.crbegin(), vector.size(), revVector.begin());
std::copy_n(vector.cbegin(), vector.size(), revVector.rbegin());

std::move(vector.crbegin(), vector.crend(), revVector.begin());
std::move(vector.cbegin(), vector.cend(), revVector.rbegin());

std::move_backward(vector.crbegin(), vector.crend(), revVector.end());
std::move_backward(vector.cbegin(), vector.cend(), revVector.rend());

std::reverse(vector.begin(), vector.end());
std::reverse(vector.rbegin(), vector.rend());

std::reverse_copy(vector.cbegin(), vector.cend(), revVector.begin());
std::reverse_copy(vector.crbegin(), vector.crend(), revVector.rbegin());

std::transform(vector.crbegin(), vector.crend(), revVector.begin(), [](int i){return i;});
std::transform(vector.cbegin(), vector.cend(), revVector.rbegin(), [](int i){return i;});