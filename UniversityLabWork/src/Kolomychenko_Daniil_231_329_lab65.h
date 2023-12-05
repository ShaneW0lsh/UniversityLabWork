#pragma once

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <vector>

namespace lab65 {
    void launch();
    std::vector<std::string> split(std::string in);
    void print_student_list();
    void distribute_students();

    struct Student {
        std::string group_number;
        std::string name;

        Student(std::string group_number, std::string name);
        Student(const Student& other);
        void print();
    };
}