#include "Kolomychenko_Daniil_231_329_lab62.h"

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
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] != ' ') deq.push_back(tolower(input[i]));
    }

    while (deq.size() > 1) {
        if (deq.front() != deq.back()) return false;
        deq.pop_front();
        deq.pop_back();
    }
    return true;
}

void lab62::Point::print()
{
    std::cout << "Coordinates: " << x << ", " << y << '\n';
}

// if positive then C is on the left of vector AB
// negative => right
double get_area(lab62::Point A, lab62::Point B, lab62::Point C)
{
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

lab62::Point lab62::find_base_point(std::vector<lab62::Point> &A)
{
    Point R;
    double min_x = 101239812.0;
    for (auto &point : A)
        min_x = std::min<double>(point.x, min_x);
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i].x == min_x) {
            R = A[i];
            std::swap(A[0], A[i]);
        }
    }
    return R;
}

std::deque<int> &lab62::scan_algo(std::vector<lab62::Point> &A)
{
    std::deque<int> *dq = new std::deque<int>;
    dq->push_front(0);
    dq->push_front(1);

    for (size_t i = 2; i < A.size(); ++i) {
        double area = get_area(A[(*dq)[1]], A[(*dq)[0]], A[i]);
        if (area > 0.0)
            dq->push_front(i);
        else {
            dq->pop_front();
            --i;
        }
    }

    return *dq;
}

void lab62::task2()
{
    std::vector<lab62::Point> A = {
        {4.0, 0.0}, {2.0, 1.0}, {5.0, 2.0}, {0.0, 0.0}, {1.0, 3.0},
        {3.0, 3.0}, {1.0, 4.0}, {2.0, 4.0}, {4.0, 5.0}, {2, 6}};

    lab62::Point R = find_base_point(A);

    // if engative => return false
    // positive => return true
    std::sort(A.begin(), A.end(), [R](Point b, Point c) {
        if (get_area(R, b, c) <= 0.0) return false;
        return true;
    });

    std::deque<int> &dq = scan_algo(A);
    for (int i = dq.size() - 1; i > -1; --i)
        A[dq[i]].print();

    delete &dq;
}
