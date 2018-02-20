#ifndef HOMEWORK_TOKENHANDLER_H
#define HOMEWORK_TOKENHANDLER_H


#include <string>

class TokenHandler {
public:
    virtual void onToken(const std::string &token) = 0;

    virtual void onDelimiter(char delimiter) = 0;
};

#endif //HOMEWORK_TOKENHANDLER_H