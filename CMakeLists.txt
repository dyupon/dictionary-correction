cmake_minimum_required(VERSION 3.8)
project(HomeWork)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h Tokenizer.cpp Tokenizer.h TokenHandler.h DictionaryTokenHandler.cpp DictionaryTokenHandler.h FileWriteTokenHandler.cpp FileWriteTokenHandler.h)
add_executable(HomeWork ${SOURCE_FILES})