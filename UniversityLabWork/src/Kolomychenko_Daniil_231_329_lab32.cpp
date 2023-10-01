#include <iostream>
#include <string>

static void task1();
static void task2();
static void task3();
static void task4();

int* user_array = NULL;
int size = NULL;

void lab32() {
    while (true) {
        int user_input;
        std::cin >> user_input;
        switch (user_input) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            default:
                return;
        }
    }
}

static void task1() {
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    user_array = new int[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i)
        std::cin >> user_array[i];
}

static void task2() {
    for (int i = 0; i < size; ++i)
        std::cout << user_array[i] << ' ';
    std::cout << '\n';
}

static void task3() {

}

static void task4() {

}