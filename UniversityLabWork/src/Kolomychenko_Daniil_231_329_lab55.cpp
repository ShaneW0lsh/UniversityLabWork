#include "Kolomychenko_Daniil_231_329_lab55.h"
#include <limits>

int lab55::String::number_of_calls = 0;

bool lab55::is_inside(const char symbol, const char *str)
{
    for (int i = 0; i < calculate_length(str); ++i)
        if (str[i] == symbol) return true;

    return false;
}

char *lab55::convert_long_long_to_char(long long value)
{
    int buffer_size = std::snprintf(nullptr, 0, "%lld", value);
    char *result = new char[buffer_size + 1];
    std::snprintf(result, buffer_size + 1, "%lld", value);
    return result;
}

int lab55::calculate_length(const char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        ++len;
    return len;
}

lab55::String::String()
{
    content = new char[2];
    content[0] = '0';
    content[1] = '\0';
    length_ = 1;
}

lab55::String::String(const char *str)
{
    length_ = calculate_length(str);

    content = new char[length_ + 1];
    for (int i = 0; i < length_; ++i)
        content[i] = str[i];
    content[length_] = '\0';
}

lab55::String::String(const char symbol)
{
    content = new char[2];
    content[0] = symbol;
    content[1] = '\0';
    length_ = 1;
}

lab55::String::String(const String &copy)
    : content(copy.content), length_(copy.length_)
{
    std::cout << "Number of copy constructors calls currently is: "
              << ++number_of_calls << '\n';
}

lab55::String::~String() { delete[] content; }

int lab55::String::length() const { return length_; }

void lab55::String::clear()
{
    content = nullptr;
    length_ = 0;
}

void lab55::String::print() const { std::cout << content; }

std::ostream &lab55::operator<<(std::ostream &os, const String &str)
{
    os << str.content;
    return os;
}

bool lab55::IntegerString::valid_string(const char *str) const
{
    if (str[0] == '0' and calculate_length(str) == 1) return false;

    const char approved_symbols[] = "0123456789-+";
    for (int i = 0; i < calculate_length(str); ++i) {
        if (i != 0 and (str[i] == '+' or str[i] == '-')) return false;
        if (!is_inside(str[i], approved_symbols)) return false;
    }
    return true;
}

lab55::IntegerString::IntegerString() : String() {}

lab55::IntegerString::IntegerString(const char *str)
{
    if (valid_string(str)) {
        length_ = calculate_length(str);

        content = new char[length_ + 1];
        for (int i = 0; i < length_; ++i)
            content[i] = str[i];
        content[length_] = '\0';
    } else {
        length_ = 1;

        content = new char[2];
        content[0] = '0';
        content[1] = '\0';
    }
}

lab55::IntegerString::IntegerString(const IntegerString &copy) : String(copy)
{
    std::cout << "Number of copy constructors calls currently is: "
              << ++number_of_calls << '\n';
}

lab55::IntegerString::~IntegerString() {}

// for some reason const should be used in order for cout to work
lab55::IntegerString
lab55::IntegerString::operator-(const IntegerString &other) const
{
    char *end_ptr1, *end_ptr2;
    long long first_value = std::strtoll(content, &end_ptr1, 10);
    long long second_value = std::strtoll(other.content, &end_ptr2, 10);
    long long result = first_value - second_value;
    IntegerString is_result = IntegerString(convert_long_long_to_char(result));

    return is_result;
}

bool lab55::IntegerString::operator<(const IntegerString &other) const
{
    char *end_ptr1, *end_ptr2;
    long long first_value = std::strtoll(content, &end_ptr1, 10);
    long long second_value = std::strtoll(other.content, &end_ptr2, 10);

    return first_value < second_value;
}

bool lab55::IntegerString::operator>(const IntegerString &other) const
{
    char *end_ptr1, *end_ptr2;
    long long first_value = std::strtoll(content, &end_ptr1, 10);
    long long second_value = std::strtoll(other.content, &end_ptr2, 10);

    return first_value > second_value;
}

bool lab55::IntegerString::fits_in_integer() const
{
    char *end_ptr;
    long long converted = std::strtoll(content, &end_ptr, 10);
    return (converted <= std::numeric_limits<int>::max() &&
            converted <= std::numeric_limits<int>::min());
}

void lab55::launch()
{
    IntegerString is1;
    IntegerString is2 = "29";
    IntegerString is3 = "-39";
    std::cout << is1 << std::endl;
    std::cout << is2 - is3 << std::endl;
    std::cout << "is2 fits inside int: " << is2.fits_in_integer() << std::endl;
    std::cout << "is2 > is3: " << (is2 > is3) << std::endl;
    std::cout << "is2 < is3: " << (is2 < is3) << std::endl;
    std::cout << "Lengths of objects:\n"
              << is1.length() << '\n'
              << is2.length() << '\n'
              << is3.length();
}
