#include <iostream>
#include <vector>
#include <string>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int R;
        int C;
        std::cin >> R >> C;
        std::vector<std::vector<char>> board;
        std::string directions = "";

        for (int i = 0; i < R; i++) {
            std::vector<char> row;
            for (int j = 0; j < C; j++) {
                char temp;
                std::cin >> temp;
                row.push_back(temp);
            }
            board.push_back(row);
        }

        std::cout << "Case #" << test_case + 1 << ": " << directions << "\n";
    }
}