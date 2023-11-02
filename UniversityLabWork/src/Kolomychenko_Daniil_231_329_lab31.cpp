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
static int split(std::string& user_input, T* arr);

static void task1();
static void task2();
static void task3();

void lab31() {
    while (true) {
        std::cout << "Enter 1 to test bubble sort, 2 to test counting sort, 3 to test merge sort and 4 to quit: ";
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
            case 3:
                task3();
                break;
            default:
                return;
        }
    }
}

static void task1() {
    int arr[1000] = { 0 };

    std::cout << "Enter int array: ";
    std::string user_input;
    getline(std::cin, user_input);

    int last_index = split<int>(user_input, arr);

    bubble_sort(arr, last_index);

    for (int i = 0; i < 1000; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

static void task2() {
    char arr[1000] = { '0' };

    std::cout << "Enter char array: ";
    std::string user_input;
    getline(std::cin, user_input);

    int last_index = split<char>(user_input, arr);

    count_sort(arr, last_index);

    for (int i = 0; i < 1000; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

static void task3() {
    int arr[1000] = { 0 };

    std::cout << "Enter int array: ";
    std::string user_input;
    getline(std::cin, user_input);

    int last_index = split<int>(user_input, arr);

    merge_sort(arr, last_index);

    for (int i = 0; i < 1000; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

template<typename T>
static int split(std::string& user_input, T* arr) {
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
    return current_index;
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
    int l2 = m + 1;

    if (arr[m] <= arr[l2]) return;

    while (l <= m && l2 <= r) {
        if (arr[l] <= arr[l2]) 
            l++;
        else {
            int value = arr[l2];
            int index = l2;

            while (index != l) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[l] = value;

            l++;
            m++;
            l2++;
        }
    }
}