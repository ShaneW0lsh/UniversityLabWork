#include "Kolomychenko_Daniil_231_329_lab63.h"

void lab63::launch()
{
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::greater<int>> numbers;
    std::set<int> visited;
    numbers.push(1);
    visited.insert(1);

    for (int i = 0; i < n; ++i) {
        int current = numbers.top();
        numbers.pop();

        std::cout << current << " ";

        for (int factor : {2, 3, 5}) {
            int next_number = current * factor;
            // check if next_number is not in visited
            if (visited.find(next_number) == visited.end()) {
                numbers.push(next_number);
                visited.insert(next_number);
            }
        }
    }
}
