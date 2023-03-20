#include <iostream>
#include <vector>
#include <algorithm>

double getMedian(std::vector<unsigned int> a) {
    std::sort(a.begin(), a.end());
    if (a.size() % 2 == 0) {
        return (a[a.size()/2] + a[a.size()/2 - 1]) / 2.0;
    } else {
        return a[a.size()/2];
    }
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int N;
        int M;
        std::cin >> N >> M;
        std::vector<unsigned int> regionValues;
        
        for (int i = 0; i < N; i++) {
            unsigned int temp;
            std::cin >> temp;
            regionValues.push_back(temp);
        }

        double solution = 0.0;

        std::sort(regionValues.rbegin(), regionValues.rend());

        for (int i = 0; i < M - 1; i++) {
            solution += regionValues[i];
        }        
        solution += getMedian(std::vector<unsigned int> (regionValues.begin() + M - 1, regionValues.end()));

        std::cout << "Case #" << test_case + 1 << ": " << solution << "\n";
    }
}