#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

namespace lab7 {
    struct Person;

    // Обобщенная функция быстрой сортировки с использованием std::function<>
    template<typename T>
    void quick_sort(std::vector<T>& arr, int low, int high,
        std::function<bool(const T&, const T&)> compare);
    void launch();
}