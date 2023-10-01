#include <iostream>
#include <functional>
#include <string>
#include <sstream>

void bubble_sort(int* arr, const int size);

void count_sort(char* arr, const int size);

void merge_sort(int* arr, int size);
void merge_sort_recursion(int* arr, int l, int r);
void merge_sorted_arrays(int* arr, int l, int m, int r);

template<typename T>
void split(std::string& user_input, T* arr);

template<typename T>
void task(std::function<void(T* arr, const int size)> sorting_algorithm);


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

template<typename T>
void task(std::function<void(T* arr, const int size)> sorting_algorithm) {
    T arr[1000] = { 0 };

    std::string user_input;
    getline(std::cin, user_input);

    split<T>(user_input, arr);

    sorting_algorithm(arr, 1000);

    for (int i = 0; i < 1000; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
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

void merge_sort(int* arr, int size) {
    merge_sort_recursion(arr, 0, size - 1);
}

void merge_sort_recursion(int* arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;

    merge_sort_recursion(arr, l, m);
    merge_sort_recursion(arr, m + 1, r);

    merge_sorted_arrays(arr, l, m, r);
}

void merge_sorted_arrays(int* arr, int l, int m, int r) {
    int left_length = m - l + 1;
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

}