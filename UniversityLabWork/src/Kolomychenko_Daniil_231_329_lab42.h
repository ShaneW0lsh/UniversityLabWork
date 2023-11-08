#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace lab42 {
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
    void launch();
}