#include "Kolomychenko_Daniil_231_329_lab7.h"

struct lab7::Person {
    std::string surname;
    std::string name;
    int age;
};

// Обобщенная функция быстрой сортировки с использованием std::function<>
template <typename T>
void lab7::quick_sort(std::vector<T> &arr, int low, int high,
                      std::function<bool(const T &, const T &)> compare)
{
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
        quick_sort(arr, low, pivotIndex - 1, compare);
        quick_sort(arr, pivotIndex + 1, high, compare);
    }
}

void lab7::launch()
{
    std::vector<Person> people = {
        {"Doe", "John", 30},
        {"Smith", "Alice", 25},
        {"Johnson", "Bob", 35},
    };

    quick_sort<Person>(
        people, 0, people.size() - 1,
        [](const Person &a, const Person &b) { return a.surname < b.surname; });

    std::cout << "Sorted by Surname:" << std::endl;
    for (const auto &person : people) {
        std::cout << person.surname << " " << person.name << " " << person.age
                  << std::endl;
    }

    quick_sort<Person>(
        people, 0, people.size() - 1,
        [](const Person &a, const Person &b) { return a.name < b.name; });

    std::cout << "Sorted by Name:" << std::endl;
    for (const auto &person : people) {
        std::cout << person.surname << " " << person.name << " " << person.age
                  << std::endl;
    }

    quick_sort<Person>(
        people, 0, people.size() - 1,
        [](const Person &a, const Person &b) { return a.age < b.age; });

    std::cout << "Sorted by Age:" << std::endl;
    for (const auto &person : people) {
        std::cout << person.surname << " " << person.name << " " << person.age
                  << std::endl;
    }

    std::vector<int> numbers = {100, 1, 3, 5, -1, 0, 10};
    quick_sort<int>(numbers, 0, numbers.size() - 1,
                    [](const int &a, const int &b) { return a < b; });
    for (const int &number : numbers) {
        std::cout << number << ' ';
    }
}
