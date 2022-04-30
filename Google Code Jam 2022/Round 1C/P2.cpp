#include <iostream>
#include <vector>
#include <math.h>

bool isSquary (std::vector<int> elements) {
    long long sumOfSquares = 0;
    long long squareOfSums = 0;
    
    for (auto e : elements) {
        sumOfSquares += e*e;
        squareOfSums += e;
    }
    squareOfSums*=squareOfSums;
    return squareOfSums == sumOfSquares;
}

int main() {
    int test_cases;
    std::cin >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++) {
        std::vector<long long> answer;
        bool impossible = false;
        int N;
        int K;
        std::cin >> N >> K;
        std::vector<int> list_elements;
        
        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >> temp;
            list_elements.push_back(temp);
        }

        if (isSquary(list_elements)) {
            answer.push_back(0);
        } else {
            long long sumOfSquares = 0;
            long long sum = 0;
            for (auto e : list_elements) {
                sumOfSquares += e*e;
                sum += e;
            }
            long long xCoeff = 0;
            xCoeff = 2 * sum;
            sum = sum * sum;
            if (xCoeff == 0) {
                impossible = true;
            } else {
                long long temp = sumOfSquares + (-1*sum);
                if (temp % xCoeff != 0) {
                    impossible = true;
                } else {
                    long long y = (sumOfSquares + (-1*sum)) / xCoeff;
                    long long bound = pow(10, 18);
                    if (y >= bound || y <= (-1*bound)) {
                        impossible = true;
                    } else {
                        answer.push_back(y);
                    }
                }
            }
        }

        std::cout << "Case #" << test_case + 1 << ":";
        if (!impossible) {
            for (auto a : answer) {
                std::cout << " " << a;
            }
            std::cout << "\n";
        } else {
            std::cout << " IMPOSSIBLE\n";
        }
    }
}