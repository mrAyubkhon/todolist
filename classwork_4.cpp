#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int id;
    double grade;
};
void addStudent(std::vector<Student>& students) {
    Student newStudent;
    std::cout << "Enter student's name: ";
    std::cin >> newStudent.name;
    std::cout << "Enter student's ID: ";
    std::cin >> newStudent.id;
    std::cout << "Enter student's grade: ";
    std::cin >> newStudent.grade;
    students.push_back(newStudent);
}
void displayStudents(const std::vector<Student>& students) {
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << ", ID: " << student.id << ", Grade: " << student.grade << std::endl;
    }
}
int main() {
    std::vector<Student> students;

    int choice;
    do {
        std::cout << "Menu:\n1. Add Student\n2. Display Students\n3. Quit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
