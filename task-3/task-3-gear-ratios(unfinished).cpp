// #include <iostream>
// #include <fstream>
// #include <string>
// #include <map>
// #include <vector>
// #include <cctype>
// #include <numeric>


// int main() {
//     // Open file
//     std::ifstream inputFile("input.txt");

//     std::string inputLine1, inputLine2, inputLine3;

//     std::map<int, std::vector<int>> lineNumbersToValidNums;

//     std::getline(inputFile, inputLine2) && std::getline(inputFile, inputLine3);

//     int lineNumber = 1;

//     do {

//         if (lineNumber != 1) { inputLine1 += '.'; }
//         inputLine2 += '.';
//         inputLine3 += '.';

//         size_t pos = 0;
//         int num;

//         if (inputFile.peek() == EOF) {
//             inputLine1 = inputLine2;
//             inputLine2 = inputLine3;
//         }

//         while (pos < inputLine2.length()) {

//             // if we encounter a number
//             if (isdigit(inputLine2[pos])) {
//                 std::string numberStr;

//                 int startPos = (pos == 0) ? 0 : pos - 1;

//                 // find whole number
//                 while (pos < inputLine2.length() && isdigit(inputLine2[pos])) {
//                     numberStr += inputLine2[pos];
//                     pos++;
//                 }

//                 int endPos = pos;

//                 // check if there are symbols on either side of the number
//                 if ((!isdigit(inputLine2[startPos]) && inputLine2[startPos] != '.') || 
//                     (!isdigit(inputLine2[endPos]) && inputLine2[endPos] != '.')) {
//                         num = std::stoi(numberStr);
//                         lineNumbersToValidNums[lineNumber].push_back(num);
//                         break;
//                     }

//                 while (startPos <= endPos) {
//                     if ((!isdigit(inputLine1[startPos]) && inputLine1[startPos] != '.' && !inputLine1.empty()) ||
//                         (!isdigit(inputLine3[startPos]) && inputLine3[startPos] != '.')) {
//                         num = std::stoi(numberStr);
//                         lineNumbersToValidNums[lineNumber].push_back(num);
//                         break;
                        
//                     } else startPos++;
//                 }

//             } else pos++;
//         }

//         inputLine1 = inputLine2; 
//         inputLine2 = inputLine3;
//         lineNumber++;

//     } while (std::getline(inputFile, inputLine3));

//    int totalSum = 0;
//     for (const auto& pair : lineNumbersToValidNums) {
//         for (int num : pair.second) {
//             totalSum += num;
//         }
//     }

//     std::cout << "Total sum is: " << totalSum << std::endl;

//     // Close the file
//     inputFile.close();

//     return 0;
// }
