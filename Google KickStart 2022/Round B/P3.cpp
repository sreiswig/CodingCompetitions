#include <iostream>
#include <vector>

int computeDistance(int a, int b, int d) {
    int diff = std::abs(a-b);
    if (diff > d/2) {
        return d - (a-b);
    } else {
        return diff;
    }
}

int recursiveLockPick(std::vector<int> sections, int D, int mustContain) {
    // every section is same value and want to become 0
    if (sections.size() == 1) {
        return computeDistance(sections[0], 0, D);
    }

    if (mustContain == 0) {
        return computeDistance(sections[0], sections[1], D) + recursiveLockPick(std::vector<int>(sections.begin()+1, sections.end()), D, 0);; 
    } else if (mustContain == sections.size() - 1) {
        return computeDistance(sections[mustContain], sections[mustContain-1], D) + recursiveLockPick(std::vector<int>(sections.begin(), sections.end()-1), D, mustContain-1);
    } else {
        std::vector<int> left;
        std::vector<int> right;
        for (int i = 0; i < mustContain; i++) {
            right.push_back(sections[i]);
            if (i != mustContain - 1) {
                left.push_back(sections[i+1]);
            }
        }
        for (int i = mustContain + 1; i < sections.size(); i++) {
            left.push_back(sections[i]);
            if (i != mustContain + 1) {
                right.push_back(sections[i-1]);
            }
        }
        return std::min(computeDistance(sections[mustContain], sections[mustContain-1], D) + recursiveLockPick(left, D, mustContain),
                        computeDistance(sections[mustContain], sections[mustContain+1], D) + recursiveLockPick(right, D, mustContain+1));
    }
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int N;
        int D;
        
        std::cin >> N >> D;
        std::vector<int> lock;

        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >>temp;
            lock.push_back(temp);
        }

        std::vector<int> sections;
        int index = 0;
        int val = lock[index];
        while (index < lock.size()) {
            if (lock[index] != val) {
                sections.push_back(val);
                val = lock[index];
            }
            index++;
        }
        sections.push_back(val);

        int min = INT32_MAX;
        for (int i = 0; i < sections.size(); i++) {
            int temp = recursiveLockPick(sections, D, i);
            if (temp < min) {
                min = temp;
            }
        }

        std::cout << "Case #" << test_case + 1 << ": " << min << "\n";
    }
}