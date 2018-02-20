#include <iostream>
#include "Dictionary.h"

void Dictionary::addWord(const std::string &word, bool addAsNew) {
    words.insert(word);
    if (addAsNew) {
        newWords.insert(word);
    }
}

bool Dictionary::containsWord(const std::string &word) const {
    return words.find(word) != words.end();
}

std::vector<std::string> Dictionary::findNearestWords(const std::string &word) const {
    std::vector<std::string> nearestWords;
    for (const auto &currentWord : words) {
        if (distance(word, currentWord) == 1) {
            nearestWords.push_back(currentWord);
        }
    }
    return nearestWords;
}

size_t Dictionary::distance(const std::string &left, const std::string &right) const {
    const size_t m = left.size();
    const size_t n = right.size();
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    std::vector<std::vector<size_t> > matrix;
    matrix.reserve(m + 1);

    for (size_t i = 0; i <= m; ++i) {
        std::vector<size_t> row;
        row.reserve(n + 1);
        row.push_back(i);
        matrix.push_back(row);
    }
    for (size_t i = 0; i <= n; ++i) {
        matrix[0].push_back(i);
    }

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            size_t cost = left[i - 1] == right[j - 1] ? 0 : 1;
            size_t upperCell = matrix[i - 1][j];
            size_t leftCell = matrix[i][j - 1];
            size_t upperLeftCell = matrix[i - 1][j - 1];
            size_t cellValue = std::min(std::min(upperCell + 1, leftCell + 1), upperLeftCell + cost);
            matrix[i].push_back(cellValue);
        }
    }

    return matrix[m][n];
}

std::set<std::string> Dictionary::getNewWords() {
    return newWords;
}
