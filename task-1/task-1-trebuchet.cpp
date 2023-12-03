#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cctype>

int main() {
    // Open the file
    std::ifstream inputFile("input.txt");

    // Check if the file could be open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1; // Return an error code
    }

    std::unordered_map<std::string, std::string> numbersDict = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    };

    int sum = 0;

    // Read the file line by line
    std::string line;

    while (std::getline(inputFile, line)) {

        std::string numString;

        // Iterate over characters in the line
        for (size_t pos = 0; pos < line.length(); ++pos) {
            if (std::isdigit(line[pos])) {
                // If it's a digit, add it to numString
                numString += line[pos];
            } else if (std::isalpha(line[pos])) {
                // If it's a letter, check for spelled-out numbers
                std::string letteredNum;
                for (int i = pos; i < line.length(); ++i) {
                    if (std::isalpha(line[i])) {
                        letteredNum += line[i];
                        if (numbersDict.find(letteredNum) != numbersDict.end()) {
                            numString += numbersDict[letteredNum];
                            pos = i-1;
                            break;
                        }
                    } else {
                        break;  // Break if a non-alphabetic character is encountered
                    }
                }
            }
        }

        // Combine the first and last occurrences and add to the sum
        if (!numString.empty()) {
            numString = numString.substr(0, 1) + numString.substr(numString.length() - 1, 1);
            sum += std::stoi(numString);
        }
    }

    std::cout << "The final sum is: " << sum << std::endl;

    // Close the file
    inputFile.close();

    return 0; // Return success
}
