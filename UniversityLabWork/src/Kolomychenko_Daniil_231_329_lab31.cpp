#include <iostream>
#include <functional>
#include <string>

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

/* write a split function and rewrite it with getline() */
void task(std::function<void(int* arr, const int size)> sorting_algorithm) {
    int arr[1000] = { 0 };
    int current_index = 0;

    /*while (true) {
        std::string user_input;
        std::cin >> user_input;
        if (user_input == "stop") break;
        arr[current_index] = stoi(user_input);
        ++current_index;
    }*/




    sorting_algorithm(arr, 1000);

    for (int i = 0; i < 1000; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}


void lab31() {
    while (true) {
        int user_input;
        std::cin >> user_input;
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