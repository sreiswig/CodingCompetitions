#include <iostream>
#include <vector>

int main() {
    int total = 0;
    for (int i = 0; i < 100; i++) {
        total+= i+1;
    }
    std::cout << total << "\n";
}