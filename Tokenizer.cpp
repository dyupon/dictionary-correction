#include "Tokenizer.h"

Tokenizer::Tokenizer(const std::string &_delimiters, TokenHandler &_tokenHandler) : delimiters(_delimiters),
                                                                                    tokenHandler(_tokenHandler) {
}

void Tokenizer::tokenize(std::istream &inputStream) {
    char currentSymbol;
    std::string currentWord;
    while (inputStream.get(currentSymbol)) {
        if (delimiters.find(currentSymbol) != std::string::npos) {
            if (!currentWord.empty()) {
                tokenHandler.onToken(currentWord);
                currentWord = "";
            }
            tokenHandler.onDelimiter(currentSymbol);
        } else {
            currentWord += currentSymbol;
        }
    }
    if (!currentWord.empty()) {
        tokenHandler.onToken(currentWord);
    }
}
