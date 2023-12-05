#pragma once
#include <iostream>
#include <vector>

namespace lab41 {

    struct SubstringIndices {
        int* arr;
        int length;
        SubstringIndices(int* arr, int length)
            :arr(arr), length(length)
        {
        }
    };

    void task1();
    void task2();
    void task3();
    void task4();

    bool palindrome(char* str);
    SubstringIndices find_substring(const char* str, const char* substr);
    bool equals(const char* str1, const char* str2);
    void print_string(const char* str);
    void encrypt(char* str_to_encrypt, int key);
    void launch();
}