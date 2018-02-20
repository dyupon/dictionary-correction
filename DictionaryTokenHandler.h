#ifndef HOMEWORK_DICTIONARYTOKENHANDLER_H
#define HOMEWORK_DICTIONARYTOKENHANDLER_H


#include "TokenHandler.h"
#include "Dictionary.h"

class DictionaryTokenHandler : public TokenHandler {
public:
    explicit DictionaryTokenHandler(Dictionary &dictionary);

    void onToken(const std::string &token) override;

    void onDelimiter(char delimiter) override;

private:
    Dictionary &dictionary;
};

#endif //HOMEWORK_DICTIONARYTOKENHANDLER_H