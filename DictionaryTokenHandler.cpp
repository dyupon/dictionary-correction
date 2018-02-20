#include "DictionaryTokenHandler.h"

void DictionaryTokenHandler::onToken(const std::string &token) {
    dictionary.addWord(token);
}

DictionaryTokenHandler::DictionaryTokenHandler(Dictionary &_dictionary) : dictionary(_dictionary) {
}

void DictionaryTokenHandler::onDelimiter(char delimiter) {
}
