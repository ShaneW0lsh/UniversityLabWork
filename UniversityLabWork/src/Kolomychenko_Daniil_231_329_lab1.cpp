#include <iostream>
#include <limits>
#include <string>
#include <vector>

template<typename T>
void printTypeInfo(std::string class_name) {
	if (class_name == "char") {
		std::cout << "min " << class_name << " = " << (long long)std::numeric_limits<T>::min() << ", "
			<< "max " << class_name << " = " << (long long)std::numeric_limits<T>::max() << ", "
			<< "size of " << class_name << " = " << sizeof(T) << std::endl;
	}
	else {
		std::cout << "min " << class_name << " = " << std::numeric_limits<T>::min() << ", "
			<< "max " << class_name << " = " << std::numeric_limits<T>::max() << ", "
			<< "size of " << class_name << " = " << sizeof(T) << std::endl;

	}
}

std::vector<int> to_base_of(int input, int base) {
	std::vector<int> result;
	while (input) {
		result.push_back(input % base);
		input /= base;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

void lab1() {
	setlocale(LC_ALL, "Rus");

	std::cout << "1.\n";
	std::cout << "Kolomychenko Daniil Maximovich, 231-329" << std::endl;

	std::cout << "2.\n";
	printTypeInfo<int>("int");
	printTypeInfo<unsigned int>("unsigned int");
	printTypeInfo<short>("short");
	printTypeInfo<unsigned short>("unsigned short");
	printTypeInfo<long>("long");
	printTypeInfo<long long>("long long");
	printTypeInfo<double>("double");
	printTypeInfo<char>("char");
	printTypeInfo<bool>("bool");

	std::cout << "3.\n";
	std::cout << "Введите число: ";
	int input = 0;
	std::cin >> input;
	auto result1 = to_base_of(input, 2);
	std::cout << "В бинарном виде ";
	for (int& element : result1)
		std::cout << element;
	std::cout << std::endl;
	std::cout << "В шестнадцетиричном виде: ";
	auto result2 = to_base_of(input, 16);
	for (int& element : result2)
		std::cout << element;
	std::cout << std::endl;
	std::cout << "bool " << static_cast<bool>(input) << std::endl;
	std::cout << "double " << static_cast<double>(input) << std::endl;
	std::cout << "char " << static_cast<char>(input) << std::endl;

	std::cout << "4.\n";
	std::cout << "Введите коэффициенты a * x = b: ";
	int a, b;
	std::cin >> a >> b;
	std::cout << a << " * x = " << b << std::endl;
	std::cout << "x = " << b << " / " << a << std::endl;
	std::cout << "x = " << 1.0f * b / a << std::endl;
	std::cout << "Ответ: " << 1.0f * b / a << std::endl;

	std::cout << "5.\n";
	std::cout << "Введите координаты отрезка на прямой: ";
	int c1, c2;
	std::cin >> c1 >> c2;
	std::cout << "Середина отрезка находится в точке с координатой " << std::round((c1 + c2) / 2);
}