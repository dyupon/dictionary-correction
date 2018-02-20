#ifndef HOMEWORK_INPUTTEXTTOKENHANDLER_H
#define HOMEWORK_INPUTTEXTTOKENHANDLER_H

#include "TokenHandler.h"
#include "Dictionary.h"

class FileWriteTokenHandler : public TokenHandler {
public:
    FileWriteTokenHandler(std::ofstream &_outputFile, Dictionary &_dictionary);

    void onToken(const std::string &token) override;

    void onDelimiter(char delimiter) override;

private:
    std::string processWordByUser(const std::string &word) const;

    std::ofstream &outputFile;
    Dictionary &dictionary;
};

#endif //HOMEWORK_INPUTTEXTTOKENHANDLER_H
