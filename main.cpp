#include <iostream>
#include <fstream>
#include <sstream>
#include "Dictionary.h"
#include "DictionaryTokenHandler.h"
#include "Tokenizer.h"
#include "FileWriteTokenHandler.h"


int main(int argc, char *argv[]) {
    const std::string delimiters = ",. =-+*/;:_()'\"\n\t";

    std::fstream inputDictionaryFile("dictionary.txt");

    Dictionary dictionary;
    DictionaryTokenHandler dictionaryTokenHandler(dictionary);
    Tokenizer dictionaryTokenizer(delimiters, dictionaryTokenHandler);
    dictionaryTokenizer.tokenize(inputDictionaryFile);
    inputDictionaryFile.close();

    std::ifstream inputFile("text.txt");
    std::ofstream outputFile("out.txt");

    FileWriteTokenHandler fileWriteTokenHandler(outputFile, dictionary);
    Tokenizer inputFileTokenizer(delimiters, fileWriteTokenHandler);
    inputFileTokenizer.tokenize(inputFile);

    inputFile.close();
    outputFile.close();

    std::set<std::string> newWords = dictionary.getNewWords();
    if (!newWords.empty()) {
        std::ofstream outputDictionaryFile("dictionary.txt", std::ofstream::out | std::ofstream::app);
        outputDictionaryFile << std::endl;
        for (const auto &newWord : newWords) {
            outputDictionaryFile << newWord << std::endl;
        }
        outputDictionaryFile.close();
    }

    return 0;
}