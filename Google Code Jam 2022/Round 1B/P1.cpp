#include <iostream>
#include <queue>

int main() {
    int test_cases;
    std::cin >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++) {
        int answer = 0;
        int N;
        std::cin >> N;
        std::deque<int> ihopStack;
        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >> temp;
            ihopStack.push_back(temp);
        }
        
        int currMax = 0;
        while (!ihopStack.empty()) {
            if (ihopStack.front() <= ihopStack.back()) {
                if (ihopStack.front() >= currMax) {
                    currMax = ihopStack.front();
                    answer++;
                }
                ihopStack.pop_front();
            } else {
                if (ihopStack.back() >= currMax) {
                    currMax = ihopStack.back();
                    answer++;
                }
                ihopStack.pop_back();
            }
        }
        
        std::cout << "Case #" << test_case + 1 << ": " << answer << "\n";
    }
}