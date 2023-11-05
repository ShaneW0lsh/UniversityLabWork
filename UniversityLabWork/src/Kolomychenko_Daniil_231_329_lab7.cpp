#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

struct Person {
    std::string surname;
    std::string name;
    int age;
};

// Обобщенная функция быстрой сортировки с использованием std::function<>
template<typename T>
void quickSort(std::vector<T>& arr, std::function<bool(const T&, const T&)> compare, int low, int high) {
    if (low < high) {
        int pivotIndex = low;
        T pivotValue = arr[high];
        for (int i = low; i < high; ++i) {
            if (compare(arr[i], pivotValue)) {
                std::swap(arr[i], arr[pivotIndex]);
                ++pivotIndex;
            }
        }
        std::swap(arr[pivotIndex], arr[high]);
        quickSort(arr, compare, low, pivotIndex - 1);
        quickSort(arr, compare, pivotIndex + 1, high);
    }
}

void lab7() {
    // Пример использования быстрой сортировки для структуры данных
    std::vector<Person> people = {
        {"Doe", "John", 30},
        {"Smith", "Alice", 25},
        {"Johnson", "Bob", 35},
        // Добавьте другие записи в вектор по вашему усмотрению
    };

    // Сортировка по фамилии
    quickSort<Person>(people, [](const Person& a, const Person& b) { return a.surname < b.surname; }, 0, people.size() - 1);

    std::cout << "Sorted by Surname:" << std::endl;
    for (const auto& person : people) {
        std::cout << person.surname << " " << person.name << " " << person.age << std::endl;
    }

    // Сортировка по имени
    quickSort<Person>(people, [](const Person& a, const Person& b) { return a.name < b.name; }, 0, people.size() - 1);

    std::cout << "Sorted by Name:" << std::endl;
    for (const auto& person : people) {
        std::cout << person.surname << " " << person.name << " " << person.age << std::endl;
    }

    // Сортировка по возрасту
    quickSort<Person>(people, [](const Person& a, const Person& b) { return a.age < b.age; }, 0, people.size() - 1);

    std::cout << "Sorted by Age:" << std::endl;
    for (const auto& person : people) {
        std::cout << person.surname << " " << person.name << " " << person.age << std::endl;
    }

    std::vector<int> numbers = {
        100, 1, 3, 5, -1, 0, 10
    };
    quickSort<int>(numbers, [](const int& a, const int& b) { return a < b; }, 0, numbers.size() - 1);
    for (const int& number : numbers) {
        std::cout << number << ' ';
    }
}