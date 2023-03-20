#include <iostream>
#include <string>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        int passwordLen;
        std::string password;
        std::cin >> passwordLen >> password;
 
        bool oneUpper = false;
        bool oneLower = false;
        bool oneDigit = false;
        bool oneSpecial = false;

        for (int i = 0; i < passwordLen; i++) {
            if (password[i] >= 'A' && password[i] <= 'Z') {
                oneUpper = true;
            } else if (password[i] >= 'a' && password[i] <= 'z') {
                oneLower = true;
            } else if (password[i] >= '0' && password[i] <= '9') {
                oneDigit = true;
            } else if (password[i] == '#' ||
                       password[i] == '@' ||
                       password[i] == '*' ||
                       password[i] == '&') {
                oneSpecial = true;
            }
        }

        if (!oneUpper) {
            password.append("A");
        }
        if (!oneLower) {
            password.append("a");
        }
        if (!oneDigit) {
            password.append("1");
        }
        if (!oneSpecial) {
            password.append("#");
        }

        if (password.size() < 7) {
            while (password.length() < 7) {
                password.append("a");
            }
        }

        std::cout << "Case #" << test_case + 1 << ": " << password << "\n";
    }
}