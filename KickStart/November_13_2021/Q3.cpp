#include <iostream>
#include <regex>

std::string sillySubstitutions(std::string s) {
    std::regex r("01");
    std::regex r2("12");
    std::regex r3("23");
    std::regex r4("34");
    std::regex r5("45");
    std::regex r6("56");
    std::regex r7("67");
    std::regex r8("78");
    std::regex r9("89");
    std::regex r10("90");
    bool changing = true;

    while (changing) {
        changing = false;
        std::smatch m;
        if (std::regex_search(s, m, r)) {
            s = std::regex_replace(s, r, "2");
            changing = true;
        }
        if (std::regex_search(s, m, r2)) {
            s = std::regex_replace(s, r2, "3");
            changing = true;
        }
        if (std::regex_search(s, m, r3)) {
            s = std::regex_replace(s, r3, "4");
            changing = true;
        }
        if (std::regex_search(s, m, r4)) {
            s = std::regex_replace(s, r4, "5");
            changing = true;
        }
        if (std::regex_search(s, m, r5)) {
            s = std::regex_replace(s, r5, "6");
            changing = true;
        }
        if (std::regex_search(s, m, r6)) {
            s = std::regex_replace(s, r6, "7");
            changing = true;
        }
        if (std::regex_search(s, m, r7)) {
            s = std::regex_replace(s, r7, "8");            
            changing = true;
        }
        if (std::regex_search(s, m, r8)) {
            s = std::regex_replace(s, r8, "9");
            changing = true;
        }
        if (std::regex_search(s, m, r9)) {
            s = std::regex_replace(s, r9, "0");
            changing = true;
        }
        if (std::regex_search(s, m, r10)) {
            s = std::regex_replace(s, r10, "1");
            changing = true;
        }
    }

    return s;
}

int main() {
    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int n;
        std::string s;
        std::cin >> n >> s;

        std::cout << "Case #" << i + 1 << ": " << sillySubstitutions(s) << "\n";
    }
}