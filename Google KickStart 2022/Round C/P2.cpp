#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        long long N, X, Y;
        std::cin >> N >> X >> Y;
        std::string result = "IMPOSSIBLE";
        bool possible = false;
        std::vector<int> alanSubset;
        std::vector<int> barberaSubset;
        long long alanSum = 0;
        long long barbaraSum = 0;

        for (int i = N; i > 0; i--) {
            if (alanSum * Y < barbaraSum * X) {
                alanSubset.push_back(i);
                alanSum += i;
            } else {
                barberaSubset.push_back(i);
                barbaraSum += i;
            }
        }

        if (alanSum * Y == barbaraSum * X) {
            result = "POSSIBLE";
            possible = true;
        }

        std::sort(alanSubset.begin(), alanSubset.end());

        std::cout << "Case #" << test_case + 1 << ": " << result << "\n";
        if(possible) {
            std::cout << alanSubset.size() << "\n";
            for(int i = 0; i < alanSubset.size(); i++) {
                std::cout << alanSubset[i] << " ";
            }
            std::cout << "\n";
        }
    }
}