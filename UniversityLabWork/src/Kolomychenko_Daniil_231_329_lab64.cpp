#include "Kolomychenko_Daniil_231_329_lab64.h"

std::set<std::string> submitted_logins;

void lab64::launch()
{
    while (true) {
        std::cout << "Enter 1 to submit test answers, 2 to exit from program: ";
        int user_input;
        std::cin >> user_input;
        switch (user_input) {
            case 1:
                task();
                break;
            default:
                return;
        }
    }
}

void lab64::task()
{
    std::cout << "Enter student login to submit test answers: ";
    std::string user_login;
    std::cin >> user_login;
    if (submitted_logins.count(user_login) > 0)
        std::cout << "Operation failed. This user has already submitted answers\n";
    else {
        std::cout << "Test answers were successfully submitted!\n";
        submitted_logins.insert(user_login);
    }
}