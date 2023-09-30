#include <iostream>
#include <string>

void triangle(int n) {
	std::string current = "";
	for (int i = 0; i <= n; ++i) {
		current += std::to_string(i);
		std::cout << current << std::endl;
	}
}

void binomials(unsigned long long n) {
	unsigned long long current_binomial = 1;
	for (unsigned long long k = 1; k <= n; ++k) {
		std::cout << current_binomial << ' ';
		current_binomial = current_binomial * (n - k + 1) / k;
	}
	std::cout << current_binomial << std::endl;
}

void task1() {
	int n;
	std::cin >> n;
	triangle(n);
}

void task2() {
	int n;
	std::cin >> n;
	binomials(n);
}

void task3() {
	int sum = 0, number = 0;
	while (true) {
		std::string element;
		std::cin >> element;
		if (element == "-1")
			break;
		++number;
		sum += stoi(element);
	}
	std::cout << sum / number << std::endl;
}

void lab2() {
	while (true) {
		std::cout << "Enter 1 to print number triangle\n2 to print n'th line of pascal triangle\n3 to find average\n";
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
			return;
		default:
			return;
		}
	}
}