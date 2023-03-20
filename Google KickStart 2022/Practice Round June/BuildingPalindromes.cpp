#include <iostream>
#include <string>
#include <unordered_map>

bool containsPalindrome(std::string s) {
    bool result = false;
    std::unordered_map<char, int> charMap;
    for (int i = 0; i < s.length(); i++) {
        charMap[s[i]]++;
    }
    int numOdd = 0;
    for (auto it = charMap.begin(); it != charMap.end(); it++) {
        if (it->second % 2 != 0) {
            numOdd++;
        }
    }
    if (numOdd <= 1) {
        result = true;
    }
    return result;
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int result = 0;
        int N, Q;
        std::cin >> N >> Q;
        std::string s;
        std::cin >> s;
        for (int i = 0; i < Q; i++) {
            int left, right;
            std::cin >> left >> right;
            if (containsPalindrome(s.substr(left-1, right-left+1))) {
                result++;
            }
        }

        std::cout << "Case #" << test_case + 1 << ": " << result << "\n";
    }
}