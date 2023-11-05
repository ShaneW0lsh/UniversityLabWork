#include <iostream>
#include <fstream>
#include <string>

std::string file_format(const std::string& file_path_full);
std::string file_name(const std::string& file_path_full);
std::string file_path(const std::string& file_path_full);
char file_disk(const std::string& file_path_full);
bool file_rename(std::string& file_path_full, const std::string& new_name);
bool file_copy(const std::string& file_path_full);
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();

void lab42() {
    while (true) {
        std::cout << "Enter:\n1 to get format of the file\n2 to get file name\n"
            "3 to get path of the file\n4 to get disk of the file\n5 to rename the file\n"
            "6 to create a file copy\n";
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
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
        }
    }
}

void task1() {
    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;
    std::cout << "File format is: " << file_format(path) << std::endl;
}

void task2() {
    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;
    std::cout << "File name is: " << file_name(path) << std::endl;
}

void task3() {
    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;
    std::cout << "File path is: " << file_path(path) << std::endl;
}

void task4() {
    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;
    std::cout << "File disk is: " << file_disk(path) << std::endl;
}

void task5() {
    std::cout << "Enter file path and new name for the file: ";
    std::string path, new_name;
    std::cin >> path >> new_name;
    if (file_rename(path, new_name))
        std::cout << "New file path: " << path << std::endl;
}

void task6() {
    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;
    if (file_copy(path))
        std::cout << "Complete!\n";
}

// на вход подается полное расположение файла, возвращает формат файла
std::string file_format(const std::string& file_path_full) {
    size_t dotIndex = file_path_full.find_last_of('.');
    if (dotIndex != std::string::npos) 
        return file_path_full.substr(dotIndex);
    return "";
}

// на вход подается полное расположение файла, возвращает название файла
std::string file_name(const std::string& file_path_full) {
    size_t slashIndex = file_path_full.find_last_of("/\\"); //find_last_of() находит последний индекс любого из символов переданного как аргумент
    if (slashIndex != std::string::npos)
        return file_path_full.substr(slashIndex + 1, file_path_full.find_last_of('.') - slashIndex - 1); // сюда передается первый индекс имени файла и количество символов в файле
    return "";
}

// на вход подается полное расположение файла, возвращает расположение файла
std::string file_path(const std::string& file_path_full) {
    size_t slashIndex = file_path_full.find_last_of("/\\");
    if (slashIndex != std::string::npos)
        return file_path_full.substr(0, slashIndex);
    return "";
}

// на вход подается полное расположение файла, возвращает диск файла
char file_disk(const std::string& file_path_full) {
    if (!file_path_full.empty())
        return file_path_full[0];
    return '\0';
}

// на вход подается полное расположение файла и новое название для файла, во время работы
// изменяется только file_path_full, возвращает тру или фолз в зависимости от успешности операции
// изменяет название файла
bool file_rename(std::string& file_path_full, const std::string& new_name) {
    std::string new_path = file_path(file_path_full) + "\\" + new_name + file_format(file_path_full);
    if (!new_name.empty() and !file_path_full.empty()) {
        file_path_full = file_path(file_path_full) + "\\" + new_name + file_format(file_path_full);
        return true;
    }
    return false;
}

// на вход подается полное расположение файла, возвращает тру или фолз в зависимости от успешности операции
// копирует контент одного файла в другой с тем же именем плюс приставка _copy
bool file_copy(const std::string& file_path_full) {
    std::ifstream source(file_path_full, std::ios::in); //std::ios::in для text mode(в нем идут преобразования для независимости от платформы)
    if (source) {
        std::string copy_path = file_path(file_path_full) 
            + "\\" + file_name(file_path_full) + "_copy" 
            + file_format(file_path_full);
        std::ofstream destination(copy_path, std::ios::out); // text mode
        if (destination) {
            destination << source.rdbuf();
            destination.close();
            source.close();
            return true;
        }
        destination.close();
    }
    source.close();
    return false;
}