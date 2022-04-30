#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

int main() {
    int test_cases;
    std::cin >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++) {
        long long answer = 0;
        
        int N;
        std::cin >> N;
        std::vector<std::string> towers;
        
        for (int i = 0; i < N; i++) {
            std::string tower;
            std::cin >> tower;
            towers.push_back(tower);
        }
        
        std::sort(towers.begin(), towers.end());
        
        // for each tower check if open or close can occur
        // stack?
        for (int i = 0; i < N; i++) {
            
        }

        std::cout << "Case #" << test_case + 1 << ": " << answer << "\n";
    }
}