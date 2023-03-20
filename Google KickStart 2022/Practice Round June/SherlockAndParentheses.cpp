#include <iostream>
#include <algorithm>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int L, R;
        std::cin >> L >> R;
        unsigned int result = 0;
        int num = std::min(L, R);
        while (num > 0) {
            result += num;
            num--;
        }
        std::cout << "Case #" << test_case + 1 << ": " << result << "\n";
    }
}