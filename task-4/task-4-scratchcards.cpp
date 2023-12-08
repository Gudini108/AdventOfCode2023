#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>


int main() {
    // Open file
    std::ifstream inputFile("input.txt");

    std::string line;

    
    int totalSum = 0;
    int lineCntr = 0;

    // For second part of the task
    int numberOfLines = std::count(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(), '\n') + 1;
    std::vector<int> scoreVector(numberOfLines, 1);

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);
    
    int secondTotalSum = 0;

    while (std::getline(inputFile, line)) {
        int numOfMatches = 0;
        int sum = 0;

        size_t colonPos = line.find(":");
        size_t pipePos = line.find("|");

        std::vector<int> leftSide, rightSide;

        if (colonPos != std::string::npos && pipePos != std::string::npos) {
            // Extract numbers after ":" but before "|"
            std::string rightSideStr = line.substr(colonPos + 1, pipePos - colonPos - 1);
            std::istringstream leftSideStream(rightSideStr);
            int num;

            while (leftSideStream >> num) { leftSide.push_back(num); }

            // Extract numbers after "|"
            std::string leftSideStr = line.substr(pipePos + 1);
            std::istringstream rightSideStream(leftSideStr);

            while (rightSideStream >> num) { rightSide.push_back(num); }
        }

        for (int num : leftSide) {
            if (std::find(rightSide.begin(), rightSide.end(), num) != rightSide.end()) { numOfMatches++; }
        }

        if (numOfMatches > 0) { sum = static_cast<int>(std::pow(2, numOfMatches - 1)); } else { sum = numOfMatches; }

        totalSum += sum;

        // For part 2 of the task
        if (numOfMatches > 0) {
            int vectorCntr = lineCntr + 1; 
            for (size_t i = 0; i < numOfMatches; ++i) { 
                scoreVector[vectorCntr] += scoreVector[lineCntr];
                vectorCntr++;
            } 
        }

        lineCntr++;

    }

    // Close the file
    inputFile.close();

    for (int value : scoreVector) {
        secondTotalSum += value;
    }

    std::cout << "Final score: " << totalSum << std::endl;
    std::cout << "Final second score: " << secondTotalSum << std::endl;

    return 0;
}
