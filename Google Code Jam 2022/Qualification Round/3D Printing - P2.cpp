#include <iostream>
#include <vector>
#include <climits>

int main() {
    int T;
    std::cin >> T;
    
    for (int test_case = 0; test_case < T; test_case++) {
        std::vector<unsigned long long> minColors = {ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX};
        for (int p = 0; p < 3; p++) {
            for (int ink = 0; ink < 4; ink++) {
                unsigned long long inkLevel;
                std::cin >> inkLevel;
                if (minColors[ink] > inkLevel) {
                    minColors[ink] = inkLevel;
                }
            }
        }
        
        unsigned long long total = 0;
        unsigned long long target = 1000000;
        for (auto min : minColors) {
            total += min;
        }
        std::cout << "Case #" << test_case + 1 << ": ";
        if (total < target) {
            std::cout << "IMPOSSIBLE" << "\n";
        } else {
            for (auto val : minColors) {
                if (target >= val) {
                    std::cout << val << " ";
                    target -= val;
                } else {
                    std::cout << target << " ";
                    target = 0;
                }
            }
            std::cout << "\n";
        }
    }
}