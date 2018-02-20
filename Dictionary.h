#ifndef HOMEWORK_DICTIONARY_H
#define HOMEWORK_DICTIONARY_H

#include <string>
#include <set>
#include <vector>
#include <fstream>

class Dictionary {
public:
    void addWord(const std::string &word, bool addAsNew = false);

    bool containsWord(const std::string &word) const;

    std::vector<std::string> findNearestWords(const std::string &word) const;

    std::set<std::string> getNewWords();

private:
    size_t distance(const std::string &left, const std::string &right) const;

    std::set<std::string> words;
    std::set<std::string> newWords;
};

#endif //HOMEWORK_DICTIONARY_H
