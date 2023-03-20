#include <iostream>
#include <vector>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int N;
        int M;
        std::cin >> N >> M;
        std::vector<unsigned int> regionValues;
        
        for (int i = 0; i < N; i++) {
            unsigned int temp;
            std::cin >> temp;
            regionValues.push_back(temp);
        }

        double soulution = 0.0;

        std::cout << "Case #" << test_case + 1 << ": " << soulution << "\n";
    }
}