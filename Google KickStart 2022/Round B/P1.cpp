#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int R;
        int A;
        int B;

        std::cin >> R >> A >> B;

        long double totalSumOfArea = 0.0;
        long double pi = 3.14159265358979323846;
        bool left = true;
        while (R > 0) {
            long double areaOfCircle = pi * pow(R, 2);
            totalSumOfArea+=areaOfCircle;
            if (left) {
                R *= A;
                left = false;
            } else {
                R /= B;
                left = true;
            }
        }
        std::cout << std::setprecision(50) << "Case #" << test_case + 1 << ": " << totalSumOfArea << "\n";
    }
}