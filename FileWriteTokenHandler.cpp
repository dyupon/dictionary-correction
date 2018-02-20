#include <iostream>
#include "FileWriteTokenHandler.h"

FileWriteTokenHandler::FileWriteTokenHandler(std::ofstream &_outputFile, Dictionary &_dictionary) : outputFile(
        _outputFile), dictionary(_dictionary) {
}

void FileWriteTokenHandler::onToken(const std::string &token) {
    if (!dictionary.containsWord(token)) {
        outputFile << processWordByUser(token);
    } else {
        outputFile << token;
    }
}

void FileWriteTokenHandler::onDelimiter(char delimiter) {
    outputFile << delimiter;
}

std::string FileWriteTokenHandler::processWordByUser(const std::string &word) const {
    do {
        std::cout << "Found unknown word: " << word << std::endl;
        std::cout << "Please, select an option: " << std::endl;
        std::cout << "1. Ignore" << std::endl;
        std::cout << "2. Add word to dictionary" << std::endl;
        std::vector<std::string> acceptableWords = dictionary.findNearestWords(word);
        if (!acceptableWords.empty()) {
            std::cout << "3. Replace by word from dictionary: " << std::endl;
            for (size_t i = 0; i < acceptableWords.size(); ++i) {
                std::cout << "\t" << i + 1 << ". " << acceptableWords[i] << std::endl;

            }
        }
        size_t selectedOption;
        std::cin >> selectedOption;
        switch (selectedOption) {
            case 1:
                return word;
            case 2:
                dictionary.addWord(word, true);
                return word;
            case 3:
                if (!acceptableWords.empty()) {
                    size_t selectedWordIndex;
                    std::cin >> selectedWordIndex;
                    if (selectedWordIndex <= acceptableWords.size()) {
                        return acceptableWords[selectedWordIndex - 1];
                    }
                }
            default:
                std::cout << "Incorrect Option. Please, select from option listed above." << std::endl;

        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    } while (true);
}
