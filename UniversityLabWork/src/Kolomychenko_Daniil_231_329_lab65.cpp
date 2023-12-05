#include "Kolomychenko_Daniil_231_329_lab65.h"

std::list<lab65::Student> students;
std::list<std::list<lab65::Student>> grouped_students;

lab65::Student::Student(std::string group_number, std::string name)
    : group_number(group_number), name(name)
{

}

lab65::Student::Student(const Student& other)
    : group_number(other.group_number), name(other.name)
{
    //std::cout << "Copy constructor was called!\n";
}

void lab65::Student::print()
{
    std::cout << group_number << ' ' << name << std::endl;
}

void lab65::launch()
{
    while (true) {
        std::cout << "Enter \"exit\" to exit or enter group number and name of student to save it:\n";

        std::string user_input;
        std::getline(std::cin, user_input);

        if (user_input == "exit") {
            distribute_students();
            print_student_list();
            break;
        }
        else {
            std::vector<std::string> splitted = split(user_input);
            if (splitted.size() != 2) { std::cout << "Invalid input\n";  continue; }

            students.emplace_back(splitted[0], splitted[1]);
        }
    }
}

void lab65::print_student_list()
{
    std::cout << "List of students:\n";
    for (auto& group : grouped_students) {
        std::cout << "Group number " << group.front().group_number << ":\n";
        for (auto& student : group)
            student.print();
    }
}

void lab65::distribute_students()
{
    for (const auto& student : students) {
        bool group_exists = false;

        for (auto& group : grouped_students) {
            if (group.front().group_number == student.group_number) {
                group.emplace_back(student.group_number, student.name);
                group_exists = true;
                break;
            }
        }

        if (!group_exists) grouped_students.emplace_back(1, student);
        std::cout << grouped_students.size() << std::endl;
    }
}

std::vector<std::string> lab65::split(std::string in)
{
    std::vector<std::string> result;
    std::string token;
    std::stringstream ss(in);
    while (getline(ss, token, ' '))
        result.push_back(token);

    return result;
}
