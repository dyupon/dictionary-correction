#ifndef HOMEWORK_TOKENIZER_H
#define HOMEWORK_TOKENIZER_H

#include <istream>
#include "TokenHandler.h"

class Tokenizer {
public:
    Tokenizer(const std::string &_delimiters, TokenHandler &_tokenHandler);

    void tokenize(std::istream &inputStream);

private:
    std::string delimiters;
    TokenHandler &tokenHandler;
};

#endif //HOMEWORK_TOKENIZER_H
