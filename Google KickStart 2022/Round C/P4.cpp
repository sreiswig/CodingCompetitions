#include <iostream>
#include <string>

bool isPalindrome(std::string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int numCandies (std::string str) {

}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int N;
        std::string s;


        
        std::cout << "Case #" << test_case + 1 << ": " << "\n";
    }
}