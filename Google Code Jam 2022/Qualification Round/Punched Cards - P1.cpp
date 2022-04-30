#include <iostream>

int main() {
    int T;
    std::cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        int R;
        int C;
        std::cin >> R >> C;
        R*=2;
        R++;
        C*=2;
        C++;
        std::cout << "Case #" << test_case + 1 << ":" << "\n";
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if(i == 0 && j == 0 ||
                   i == 0 && j == 1 ||
                   i == 1 && j == 0 ||
                   i == 1 && j == 1) {
                   std::cout << ".";
                } else if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        std::cout << "+";
                    } else {
                        std::cout << "-";
                    }
                } else {
                    if (j % 2 == 0) {
                        std::cout << "|";
                    } else {
                        std::cout << ".";
                    }
                }
            }
            std::cout << "\n";
        }
    }
}