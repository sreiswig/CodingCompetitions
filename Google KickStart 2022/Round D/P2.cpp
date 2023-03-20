#include <iostream>
#include <vector>

unsigned int getMaxQuestions(std::vector<unsigned int> a1, std::vector<unsigned int> a2, unsigned int k) {
    if (k == 0) {
        return 0;
    }

    if (a1.size() > 0 && a2.size() > 0) {
        return std::max(
            std::max(
                a1[0] + getMaxQuestions(std::vector<unsigned int>(a1.begin()+1, a1.end()), a2, k - 1),
                a1[a1.size()-1] + getMaxQuestions(std::vector<unsigned int>(a1.begin(), a1.end()-1), a2, k - 1)
            ),
            std::max(
                a2[0] + getMaxQuestions(a1, std::vector<unsigned int>(a2.begin()+1, a2.end()), k - 1),
                a2[a2.size()-1] + getMaxQuestions(a1, std::vector<unsigned int>(a2.begin(), a2.end()-1), k - 1)
            )
        );
    } else if (a1.size() > 0) {
        return std::max(
            a1[0] + getMaxQuestions(std::vector<unsigned int>(a1.begin()+1, a1.end()), a2, k - 1),
            a1[a1.size()-1] + getMaxQuestions(std::vector<unsigned int>(a1.begin(), a1.end()-1), a2, k - 1)
        );
    } else {
        return std::max(
            a2[0] + getMaxQuestions(a1, std::vector<unsigned int>(a2.begin()+1, a2.end()), k - 1),
            a2[a2.size()-1] + getMaxQuestions(a1, std::vector<unsigned int>(a2.begin(), a2.end()-1), k - 1)
        );
    }
};

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int N;
        std::cin >> N;
        std::vector<unsigned int> a1;
        for (int i = 0; i < N; i++) {
            unsigned int temp;
            std::cin >> temp;
            a1.push_back(temp);
        }

        int M;
        std::cin >> M;
        std::vector<unsigned int> a2;
        for (int i = 0; i < M; i++) {
            unsigned int temp;
            std::cin >> temp;
            a2.push_back(temp);
        }

        int K;
        std::cin >> K;


        unsigned int soulution = getMaxQuestions(a1, a2, K);

        std::cout << "Case #" << test_case + 1 << ": " << soulution << "\n";
    }
}