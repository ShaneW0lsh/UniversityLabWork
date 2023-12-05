#include "Kolomychenko_Daniil_231_329_lab61.h"

void lab61::launch()
{
    while (true) {
        std::cout << "Enter a line with symbols and brackets: ";
        std::string expression;
        std::cin >> expression;
        std::cout << is_valid_expression(expression) << std::endl;
    }
}

bool lab61::is_valid_expression(const std::string& expression)
{
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