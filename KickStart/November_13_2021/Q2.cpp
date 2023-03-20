#include <iostream>

int numStrokes(std::string painting) {
    int strokes = 0;
    bool prevRed = false;
    bool prevBlue = false;
    bool prevYellow = false;

    for (auto color : painting) {
        if (color == 'U') {
            if(prevBlue) {
                strokes++;
            }
            if(prevYellow) {
                strokes++;
            }
            if(prevRed) {
                strokes++;
            }
            prevRed = false;
            prevBlue = false;
            prevYellow = false;
        } else if (color == 'R') {
            if(prevBlue) {
                strokes++;
            }
            if (prevYellow) {
                strokes++;
            }
            prevRed = true;
            prevBlue = false;
            prevYellow = false;
        } else if (color == 'Y') {
            if(prevBlue) {
                strokes++;
            }
            if(prevRed) {
                strokes++;
            }
            prevRed = false;
            prevBlue = false;
            prevYellow = true;
        } else if (color == 'B') {
            if(prevRed) {
                strokes++;
            }
            if(prevYellow) {
                strokes++;
            }
            prevRed = false;
            prevBlue = true;
            prevYellow = false;
        } else if (color == 'O') {
            if(prevBlue) {
                strokes++;
            }
            prevRed = true;
            prevBlue = false;
            prevYellow = true;
        } else if (color == 'P') {
            if(prevYellow) {
                strokes++;
            }
            prevRed = true;
            prevBlue = true;
            prevYellow = false;
        } else if (color == 'G') {
            if (prevRed) {
                strokes++;
            }
            prevRed = false;
            prevBlue = true;
            prevYellow = true;
        } else if (color == 'A') {
            prevRed = true;
            prevBlue = true;
            prevYellow = true;
        }
    }
    if(prevBlue) {
        strokes++;
    }
    if(prevYellow) {
        strokes++;
    }
    if(prevRed) {
        strokes++;
    }
    return strokes;
}

int main() {
    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int paintingLength;
        std::cin >> paintingLength;
        std::string painting;
        std::cin >> painting;

        std::cout << "Case #" << i + 1 << ": " << numStrokes(painting) << "\n";
    }
}