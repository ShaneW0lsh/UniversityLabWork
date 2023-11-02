#include <iostream>

bool palindrome(char* str);
static void task1();

void lab41() {
    while (true) {
        int user_input;
        std::cin >> user_input;
        std::cin.ignore();
        switch (user_input) {
            case 1:
                task1();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                return;
        }
    }
}

static void task1() {
    char buffer[256];

    printf("Enter a string (up to 255 characters): ");
    fgets(buffer, sizeof(buffer), stdin);
    size_t length = strlen(buffer);
    if (buffer[length - 1] == '\n') buffer[length - 1] = '\0';

    if (palindrome(buffer)) std::cout << "It's a palindrome!\n";
    else std::cout << "It's not a palindrome!\n";
}

bool palindrome(char* str) {
    for (int i = 0, j = strlen(str) - 1; i < j; ++i, --j) {
        if (str[i] == ' ') ++i;
        if (str[j] == ' ') --j;

        if (str[i] >= 65 and str[i] <= 90)
            str[i] += 32;

        if (str[j] >= 65 and str[j] <= 90)
            str[j] += 32;

        if (str[i] != str[j])
            return false;
    }
    return true;
}