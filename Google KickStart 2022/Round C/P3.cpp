#include <iostream>
#include <vector>
#include <algorithm>

struct ant {
    long long direction;
    int label;
    long long position;
};

struct CompareAnts {
    bool operator()(const ant& a, const ant& b) {
        return a.position < b.position;
    }
};

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        long long N, L;
        std::cin >> N >> L;
        std::vector<ant> ants;

        for (int i = 1; i <= N; i++) {
            ant a;
            a.label = i;
            long long position, direction;
            std::cin >> position >> direction;
            a.direction = direction;
            a.position = position;
            ants.push_back(a);
        }

        std::sort(ants.begin(), ants.end(), CompareAnts());

        while (!ants.empty()) {
            for (auto& a : ants) {
                std::cout << "Current Ant: " << a.label << " " << a.position << " " << a.direction << "\n";
                if (a.direction == 1) {
                    a.position++;
                    if (a.position >= L) {
                        ants.pop_back();
                    }
                } else {
                    a.position--;
                    if (a.position <= 0) {
                        ants.erase(ants.begin());
                    }
                }
            }
        }

        std::cout << "Case #" << test_case + 1 << ": " << "\n";
    }
}