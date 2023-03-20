#include <iostream>
#include <string>

int minTransform(std::string s, std::string f) {
    int total = 0;
    for (auto character : s) {
        if (f.find(character) == std::string::npos) {
            int min = 27;
            for (auto character2 : f) {
                int distance = abs(character - character2);
                if (distance > 13) {
                    distance = 26 - distance;
                }
                if (distance < min) {
                    min = distance;
                }
            }
            total += min;
        }
    }
    return total;
}

int main() {
    int numTestCases;
    std::cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        std::string s;
        std::string f;
        std::cin >> s >> f;

        std::cout << "Case #" << i + 1 << ": " << minTransform(s, f) << "\n";
    }
}