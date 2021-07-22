#pragma once
#include <string>
#include <regex>
namespace Utils
{

    class Validation
    {
    public:
        static bool string_is_valid(const std::string &str);
    };

    bool Validation::string_is_valid(const std::string &str)
    {
        //regular expression to validate a string
        std::regex reg(
            "(?:[[:space:]]*"
            "([[:alpha:]_]+)"
            "[[:space:]]*)+");
        return std::regex_match(str, reg);
    }

}