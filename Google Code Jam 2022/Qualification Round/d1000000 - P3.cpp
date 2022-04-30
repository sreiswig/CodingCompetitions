#include <iostream>
#include <map>

int main() {
    int T;
    std::cin >> T;
    
    for (int test_case = 0; test_case < T; test_case++) {
        int N;
        std::cin >> N;
        std::map<int, int> numDice;
        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >> temp;
            numDice[temp]++;
        }
        int length = 0;
        
        for (auto iter : numDice) {
            while (iter.first > length && iter.second > 0) {
                length++;
                iter.second--;
            }
        }
        std::cout << "Case #" << test_case + 1 << ": " << length << "\n";
    }
}