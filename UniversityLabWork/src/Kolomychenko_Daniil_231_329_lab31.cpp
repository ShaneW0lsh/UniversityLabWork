#include <iostream>
#include <functional>
#include <string>
#include <sstream>

void bubble_sort(int* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int buff = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buff;
            }
        }
    }
}

void count_sort(int* arr, const int size) {
    const int different_elements_quantity = 26;

}

void merge_sort(int* arr, int size) {

}

void split(std::string& user_input, int* arr) {
    int current_index = 0;
    std::string token;
    std::stringstream ss(user_input);
    while (getline(ss, token, ' ')) {
        arr[current_index] = stoi(token);
        ++current_index;
    }
}

void task(std::function<void(int* arr, const int size)> sorting_algorithm) {
    int arr[1000] = { 0 };

    std::string user_input;
    getline(std::cin, user_input);
    std::cout << user_input << '\n';

    split(user_input, arr);

    sorting_algorithm(arr, 1000);

    for (int i = 0; i < 1000; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}


void lab31() {
    while (true) {
        int user_input;
        std::cin >> user_input;
        std::cin.ignore();
        switch (user_input) {
        case 1:
            task(bubble_sort);
            break;
        case 2:
            task(count_sort);
            break;
        case 3:
            task(merge_sort);
            break;
        default:
            return;
        }
    }
}