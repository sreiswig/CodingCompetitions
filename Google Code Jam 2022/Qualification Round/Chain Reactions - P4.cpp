#include <iostream>
#include <vector>

int main() {
    int T;
    std::cin >> T;
    
    for (int test_case = 0; test_case < T; test_case++) {
        std::vector<unsigned long long> funFactor;
        std::vector<int> pointers;
        int N;
        std::cin >> N;
        for (int i = 0; i < N; ++i) {
            unsigned long long temp;
            std::cin >> temp;
            funFactor.push_back(temp);
        }
        for (int i = 0; i < N; ++i) {
            int temp;
            std::cin >> temp;
            pointers.push_back(temp);
        }
        
        
    }
}