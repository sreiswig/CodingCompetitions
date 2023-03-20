#include <iostream>
#include <string>
#include <vector>

struct Point {
    int x;
    int y;
};

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int result = 0;
        int R, C;
        std::cin >> R >> C;
        
        std::vector<Point> postOfficeLocations;
        for (int i = 0; i < R; i++) {
            std::string row;
            std::cin >> row;
            for (int j = 0; j < row.size(); j++) {
                if (row[j] == '1') {
                    postOfficeLocations.push_back({j, i});
                }
            }
        }
        
        

        std::cout << "Case #" << test_case + 1 << ": " << result << "\n";
    }
}