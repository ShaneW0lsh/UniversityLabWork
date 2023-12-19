#pragma once
#include <iostream>

namespace lab55 {

    int calculate_length(const char* str);
    bool is_inside(const char symbol, const char* str);
    char* convert_long_long_to_char(long long value);

    class String {
    protected:
        char* content;
        int length_;
        static int number_of_calls;
    public:
        String();
        String(const char* str);
        String(char symbol);
        String(const String& copy);
        ~String();

        int length() const;
        void clear();
        void print() const;
        friend std::ostream& operator<<(std::ostream& os, const String& str);
    };

    class IntegerString : public String {
    private:
        bool valid_string(const char* str) const;
    public:
        IntegerString();
        IntegerString(const char* str);
        IntegerString(const IntegerString& copy);
        ~IntegerString();

        IntegerString operator-(const IntegerString& other) const;
        bool operator<(const IntegerString& other) const;
        bool operator>(const IntegerString& other) const;
        bool fits_in_integer() const;
    };

    void launch();
}