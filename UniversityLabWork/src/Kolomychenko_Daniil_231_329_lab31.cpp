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

void count_sort(char* arr, const int size) {
    const int different_elements_quantity = 26;
    int count[different_elements_quantity] = { 0 };
    for (int i = 0; i < size; ++i) {
        int j = int(arr[i] - 'a');
        ++count[j];
    }
    int i = 0, j = 0;
    while (j <= different_elements_quantity) {
        if (count[j] > 0) {
            arr[i] = char(int('a') + j);
            ++i;
            --count[j];
        }
        else ++j;
    }
}

void merge_sort(int* arr, int size) {

}

template<typename T>
void split(std::string& user_input, T* arr) {
    int current_index = 0;
    std::string token;
    std::stringstream ss(user_input);
    while (getline(ss, token, ' ')) {
        std::stringstream conv;
        conv << token;
        T converted_token;
        conv >> converted_token;
        arr[current_index] = converted_token;
        ++current_index;
    }
}

template<typename T>
void task(std::function<void(T* arr, const int size)> sorting_algorithm) {
    T arr[1000] = { 0 };

    std::string user_input;
    getline(std::cin, user_input);

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
            task<int>(bubble_sort);
            break;
        case 2:
            task<char>(count_sort);
            break;
        case 3:
            task<int>(merge_sort);
            break;
        default:
            return;
        }
    }
}