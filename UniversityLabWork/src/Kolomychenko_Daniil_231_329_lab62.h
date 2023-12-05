#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

namespace lab62 {

    void launch();
    void task1();
    bool check_palindrome(std::string input);
    void task2();

    struct Point {
        int x;
        int y;
        void print();
    };

    //std::deque<Point> P;
    //std::vector<Point> A;
}