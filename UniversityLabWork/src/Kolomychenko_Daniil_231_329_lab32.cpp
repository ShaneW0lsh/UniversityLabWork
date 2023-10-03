#include <iostream>
#include <string>

static void task1();
static void task2();
static void task3();
static void task4();

static void custom_sort1(int* arr, int length);
static void custom_sort2(int* arr, int length);
int even_position_sum(int number);

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

static void custom_sort1(int* arr, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (even_position_sum(arr[j]) > even_position_sum(arr[j+1])) {
                int buff = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buff;
            }
        }
    }
}

static void custom_sort2(int* arr, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if ( ((arr[j] % 10 == arr[j+1] % 10) and (arr[j] < arr[j+1])) || 
                 (arr[j] % 10 > arr[j+1] % 10)
            ) {
                int buff = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buff;
            }
        }
    }
}

int even_position_sum(int number) {
    std::string number_str = std::to_string(number);
    int sum = 0;
    for (int i = 1; i < number_str.length(); i += 2) {
        sum += number_str[i] - '0';
    }
    return sum;
}

static void task3() {
    custom_sort1(user_array, size);

    for (int i = 0; i < size; ++i)
        std::cout << user_array[i] << ' ';
    std::cout << '\n';
}

static void task4() {
    custom_sort2(user_array, size);

    for (int i = 0; i < size; ++i)
        std::cout << user_array[i] << ' ';
    std::cout << '\n';
}