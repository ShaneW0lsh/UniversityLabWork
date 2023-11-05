#include <stack>
#include <iostream>
#include <string>

static void task1();
bool is_valid_expression(const std::string& expression);

void lab61() {
    while (true) {
        std::cout << "Enter 1 to check expression and 2 to exit: ";
        int user_input;
        std::cin >> user_input;
        switch (user_input) {
        case 1:
            task1();
            break;
        case 2:
            return;
        }
    }
}

bool is_valid_expression(const std::string& expression) {
    std::stack<char> brackets;

    for (char bracket : expression) {
        if (bracket == '(' || bracket == '[' || bracket == '{')
            brackets.push(bracket);
        else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (brackets.empty()) {
                return false;
            }

            char open_bracket = brackets.top();
            brackets.pop();

            if ((open_bracket == '(' && bracket != ')') ||
                (open_bracket == '[' && bracket != ']') ||
                (open_bracket == '{' && bracket != '}')) {
                return false;
            }
        }
    }

    return brackets.empty();
}

static void task1() {
    std::cout << "Enter a line with symbols and brackets: ";
    std::string expression;
    std::cin >> expression;
    std::cout << is_valid_expression(expression) << std::endl;
}