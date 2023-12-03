#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int main() {
    // Open file
    std::ifstream inputFile("input.txt");

    std::string line;
    int idSum = 0;

    int idCounter = 1;

    const int redCubeCeil = 12;
    const int blueCubeCeil = 14;
    const int greenCubeCeil = 13;

    while (std::getline(inputFile, line)) {
        size_t colonPos = line.find(":");
        if (colonPos != std::string::npos) {
            // Extract the number after colon

            int colorNumber;

            size_t numPos = colonPos + 2;
            bool reachedEnd = true;

            // Continue as long as we haven't reached the end of the line
            while (numPos < line.size()) {

                if (std::isdigit(line[numPos])) {
                    colorNumber = std::stoi(line.substr(numPos));
                    int numDigits = static_cast<int>(log10(colorNumber)) + 1;
                    numPos += numDigits + 1;
                    char colorLetter = line[numPos];

                    switch (colorLetter) {
                        case 'r':
                            if (colorNumber > redCubeCeil) { reachedEnd = false; break; }
                            numPos += 3;
                            break;

                        case 'b':
                            if (colorNumber > blueCubeCeil) { reachedEnd = false; break; }
                            numPos += 4;
                            break;

                        case 'g':
                            if (colorNumber > greenCubeCeil) { reachedEnd = false; break; }
                            numPos += 5;
                            break;
                    }

                } else { numPos++; }
            }

            if (reachedEnd) { idSum += idCounter; }
        }

        idCounter++;
    }

    std::cout << "The final sum of games is: " << idSum << std::endl;

    // Close the file
    inputFile.close();

    return 0;
}
