#include <iostream>
#include <string>
#include <sstream>

void triangle(int n);
void binomials(unsigned long long n);
static void task1();
static void task2();
static void task3();

void split(std::string& user_input, int& sum, int& number);

void lab2() {
	while (true) {
		std::cout << "Enter 1 to print number triangle\n2 to print n'th line of pascal triangle\n3 to find average\n4 to exit the menu\n";
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
			case 4:
				return;
			default:
				return;
		}
	}
}

static void task1() {
	int n;
	std::cin >> n;
	triangle(n);
}

static void task2() {
	int n;
	std::cin >> n;
	binomials(n);
}

static void task3() {
	int sum = 0, number = 0;
	std::string user_input;
	getline(std::cin, user_input);
	split(user_input, sum, number);

	std::cout << 1.0 * sum / number << std::endl;
}

void split(std::string& user_input, int& sum, int& number) {
	int current_index = 0;
	std::string token;
	std::stringstream ss(user_input);
	while (getline(ss, token, ' ')) {
		sum += stoi(token);
		++number;
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

void triangle(int n) {
	std::string current = "";
	for (int i = 0; i <= n; ++i) {
		current += std::to_string(i);
		std::cout << current << std::endl;
	}
}