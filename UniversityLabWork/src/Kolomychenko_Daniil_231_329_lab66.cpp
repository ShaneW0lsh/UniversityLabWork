#include "Kolomychenko_Daniil_231_329_lab66.h"

void lab66::launch()
{
    std::cout << "Enter a text:\n";
    std::string text;
    getline(std::cin, text);

    std::string text_without_punctuation;
    for (const auto &letter : text) {
        if (!is_any(letter, ",.!?"))
            text_without_punctuation += letter;
        else
            text_without_punctuation += ' '; // there might be a problem here
    }

    std::vector<std::string> splitted = split(text_without_punctuation);

    std::map<std::string, int> word_map;
    int number_of_words = 0;
    for (auto &element : splitted) {
        ++number_of_words;
        element = to_lower(element);
        if (word_map.find(element) != word_map.end())
            ++word_map[element];
        else
            word_map[element] = 1;
    }

    for (const auto &[key, value] : word_map) {
        std::cout << key << ' ' << (int)((double)value / number_of_words * 100)
                  << '%' << std::endl;
    }
}

std::vector<std::string> lab66::split(std::string in)
{
    std::vector<std::string> result;
    std::string token;
    std::stringstream ss(in);
    while (getline(ss, token, ' '))
        result.push_back(token);

    return result;
}

bool lab66::is_any(const char letter, const std::string values)
{
    for (int i = 0; i < values.length(); ++i) {
        if (letter == values[i]) return true;
    }
    return false;
}

std::string lab66::to_lower(const std::string str)
{
    std::string result;
    for (int i = 0; i < str.length(); ++i)
        result += tolower(str[i]);
    return result;
}
