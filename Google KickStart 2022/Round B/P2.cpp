#include <iostream>
#include <vector>
#include <string>

std::vector<long long> factors(long long number) {
    std::vector<long long> factors;
    for (long long i = 1; i*i <= number; i++) {
        if (number % i == 0) {
            factors.push_back(i);
            if (i != number / i) {
                factors.push_back(number / i);
            }
        }
    }
    return factors;
}

bool isOptimizedPalindrome(long long a) {
    std::string s = std::to_string(a);
    std::string rev(s.rbegin(), s.rend());
    return s == rev;
}

bool isPalindrome(long long number) {
    std::string numberString = std::to_string(number);
    auto begin = numberString.begin();
    auto end = numberString.end();
    while (begin < end) {
        if (*begin != *(end - 1)) {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        long long A;
        std::cin >> A;
        
        std::vector<long long> factorsOfA = factors(A);
        int total = 0;
        for (auto factor : factorsOfA) {
            if(isPalindrome(factor)) {
                total++;
            }
        }
        
        std::cout << "Case #" << test_case + 1 << ": " << total << "\n";
    }
}