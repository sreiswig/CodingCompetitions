#include <iostream>
#include <vector>
#include <stack>

int main() {
    int testCases;
    std::cin >> testCases;
    
    for (int i = 0; i < testCases; i++) {
        int E;
        int W;
        int answer = 0;
        std::stack<int> bar;

        std::cin >> E >> W;
        std::vector<std::vector<int>> weightsPerExercise;
        for (int e = 0; e < E; e++) {
            std::vector<int> exercise;
            for (int w = 0; w < W; w++) {
                int weight;
                std::cin >> weight;
                exercise.push_back(weight);
            }
            weightsPerExercise.push_back(exercise);
        }
        
        for (auto exercise : weightsPerExercise) {
            for (auto weight : exercise) {
                if (bar.empty() || bar.top() < weight) {
                    bar.push(weight);
                } else {
                    answer += bar.size();
                    bar.pop();
                    bar.push(weight);
                }
            }
        }

        std::cout << "Case #" << i + 1 << ": " << answer << "\n";
    }
}