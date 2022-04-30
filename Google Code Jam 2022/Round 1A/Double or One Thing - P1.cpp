#include <iostream>
#include <string>

int main() {
    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        std::string s;
        std::cin >> s;
        
        std::string answer;
        int same = 1;
        for (int j = 1; j < s.size(); j++) {
            if (s[j-1] < s[j]) {
                for (int sa = 0; sa < same; sa++) {
                    answer+=s[j-1];
                }
                answer+=s[j-1];
                same = 1;
            } else if (s[j-1] == s[j]) {
              same+=2;  
            } else {
                for (int a = 0; a < (same + 1) / 2; a++) {
                    answer+=s[j-1];
                }
                same=1;
            }
        }
        if (same == 1) {
            answer += s.back();
        } else {
            for (int sam = 0; sam < same/2; sam++) {
                answer += s.back();
            }
            answer += s.back();
        }

        std::cout << "Case #" << i + 1 << ": " << answer << "\n"; 
    }
}