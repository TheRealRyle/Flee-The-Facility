//
// Created by Cocks Kardeiz on 25/09/2026.
//

#include "StringFunctions.h"

std::vector<std::string> StringFunctions::split(const std::string &str, char separator)
{
    std::vector<std::string> result;

    std::string entry = std::string();

    for (auto c : str) {
        if (c == separator)
        {
            result.push_back(entry);
            entry = std::string();
        } else
            entry += c;
    }

    return result;
}

std::vector<std::string> StringFunctions::split(
    const std::string_view s,
    const std::string_view delimiter)
{
    std::vector<std::string> tokens;
    auto str = s;
    std::size_t i;
    while ((i = str.find_first_of(delimiter)) != std::string::npos) {
        tokens.emplace_back(str.substr(0, i));
        str.remove_prefix(i + delimiter.length());
    }
    tokens.emplace_back(str);
    return tokens;
}
