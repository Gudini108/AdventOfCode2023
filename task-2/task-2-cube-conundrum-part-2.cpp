#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int main() {
    // Open file
    std::ifstream inputFile("input.txt");

    std::string line;
    int idSum = 0;

    while (std::getline(inputFile, line)) {
        int redCubeMax = 1;
        int blueCubeMax = 1;
        int greenCubeMax = 1;

        size_t colonPos = line.find(":");
        if (colonPos != std::string::npos) {
            // Extract the number after colon

            int colorNumber;

            size_t numPos = colonPos + 2;

            // Continue as long as we haven't reached the end of the line
            while (numPos < line.size()) {

                if (std::isdigit(line[numPos])) {
                    colorNumber = std::stoi(line.substr(numPos));
                    int numDigits = static_cast<int>(log10(colorNumber)) + 1;
                    numPos += numDigits + 1;
                    char colorLetter = line[numPos];

                    switch (colorLetter) {
                        case 'r':
                            if (colorNumber > redCubeMax) { redCubeMax = colorNumber; }
                            numPos += 3;
                            break;

                        case 'b':
                            if (colorNumber > blueCubeMax) { blueCubeMax = colorNumber; }
                            numPos += 4;
                            break;

                        case 'g':
                            if (colorNumber > greenCubeMax) { greenCubeMax = colorNumber; }
                            numPos += 5;
                            break;
                    }

                } else { numPos++; }
            }
        }

        idSum += (redCubeMax * greenCubeMax * blueCubeMax);
    }

    std::cout << "The final sum of games is: " << idSum << std::endl;

    // Close the file
    inputFile.close();

    return 0;
}
