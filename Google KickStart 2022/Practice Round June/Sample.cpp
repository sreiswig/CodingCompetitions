#include <iostream>
#include <string>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int N, M;
        std::cin >> N >> M;
        unsigned int totalCandies = 0;
        for (int i = 0; i < N; i++) {
            int numCandies;
            std::cin >> numCandies;
            totalCandies+=numCandies;
        }
        
        int result = totalCandies % M;
        
        std::cout << "Case #" << test_case + 1 << ": " << result << "\n";
    }
}