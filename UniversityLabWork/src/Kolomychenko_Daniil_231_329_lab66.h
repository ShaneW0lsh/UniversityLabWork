#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>

namespace lab66 {
    void launch();

    std::vector<std::string> split(std::string in);
    bool is_any(const char str, const std::string values);
    std::string to_lower(const std::string str);
}