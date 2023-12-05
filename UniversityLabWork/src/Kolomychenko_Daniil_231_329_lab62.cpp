#include "Kolomychenko_Daniil_231_329_lab62.h"

std::vector<lab62::Point> A = {
    {60, 30}, {55, 32}, {44, 28},
    {33, 51}, {30, 0}, {1, 30},
    {16, 30}, {7, 15}, {20, 60},
};

std::deque<int> P;

void lab62::launch()
{
    while (true) {
        std::cout << "Enter 1 to start first task, 2 to enter second task\n";
        int user_input;
        std::cin >> user_input;
        std::cin.ignore();
        switch (user_input) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            default:
                return;
        }
    }
}

void lab62::task1()
{
    std::cout << "Enter a string to check if it's a palindrome: ";
    std::string user_string;
    getline(std::cin, user_string);

    if (check_palindrome(user_string))
        std::cout << "It's a palindrome!\n";
    else
        std::cout << "Not a palindrome!\n";
}

bool lab62::check_palindrome(std::string input)
{
    std::deque<char> deq;
    for (int i = 0; i < input.length(); ++i) {
        deq.push_back(input[i]);
    }

    while (deq.size() > 1) {
        if (deq.front() != deq.back())
            return false;
        deq.pop_front();
        deq.pop_back();
    }
    return true;
}

void lab62::Point::print()
{
    std::cout << "Coordinates: " << x << ", " << y << '\n';
}

void lab62::task2()
{
    //first step
    Point R;
    int min_x = 101239812;
    for (auto& point : A)
        min_x = std::min(point.x, min_x);
    for (int i = 0; i < A.size(); ++i)
        if (A[i].x == min_x) {
            P.push_back(i);
            R = A[i];
        }
    R.print();
    //second step
    std::sort(A.begin(), A.end(), [](Point b, Point c)
    {
        return 0;
    });
}
