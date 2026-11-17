//
// Created by Cocks Kardeiz on 25/09/2026.
//

#ifndef CPPGAME_STRINGFUNCTIONS_H
#define CPPGAME_STRINGFUNCTIONS_H
#include <string>
#include <vector>


class StringFunctions {
    public:
    static std::vector<std::string> split(const std::string & str, char separator);
    static std::vector<std::string> split(std::string_view s, std::string_view delimiter);
};


#endif //CPPGAME_STRINGFUNCTIONS_H
