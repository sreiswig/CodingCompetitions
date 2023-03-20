#include <iostream>
#include <vector>

int probabilityQuery(std::vector<std::vector<int>>& probabilities, std::vector<int>& query) {
    int result = 0;
    
    return result;
}

int main() {
    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int n;
        int q;
        std::cin >> n >> q;

        int k;
        std::cin >> k;

        std::vector<std::vector<int>> probabilities;
        for (int j = 1; j < n; j++) {
            int p;
            int a;
            int b;
            std::cin >> p >> a >> b;
            probabilities.push_back({p, a, b});
        }

        std::vector<std::vector<int>> queries;
        for (int j = 0; j < q; j++) {
            int u;
            int v;
            std::cin >> u >> v;
            queries.push_back({u, v});
        }

        std::cout << "Case #" << i + 1 << ": ";
        for (auto query : queries) {
            std::cout << probabilityQuery(probabilities, query) << " ";
        }
        std::cout << "\n";
    }
}