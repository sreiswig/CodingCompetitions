#include <iostream>

int main() {
    int test_cases;
    std::cin >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++) {
        std::cout << "01010101" << std::endl;

        int response = 1;
        int rounds = 0;
        while (response != 0 && response != -1) {
            std::cin >> response;
            if(response == 1) {
                std::cout << "00110011" << std::endl;
            } else if (response == 2) {
                std::cout << "00110011" << std::endl;
            } else if (response == 3) {
                std::cout << "00000111" << std::endl;
            } else if (response == 4) {
                std::cout << "00110011" << std::endl;
            } else if (response == 5) {
                std::cout << "00110111" << std::endl;
            } else if (response == 6) {
                std::cout << "00110011" << std::endl;
            } else if (response == 7) {
                std::cout << "00110011" << std::endl;
            } else {
                std::cout << "11111111" << std::endl;
            }
        }
        if (response == -1) {
            break;
        }
    }
}