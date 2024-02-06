#pragma once
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

namespace lab62
{

void launch();
void task1();
bool check_palindrome(std::string input);
void task2();
struct Point {
    double x;
    double y;
    void print();
};

Point find_base_point(std::vector<lab62::Point> &A);
std::deque<int> &scan_algo(std::vector<lab62::Point> &A);
} // namespace lab62
