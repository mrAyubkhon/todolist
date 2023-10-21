#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

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

    
    if (newStudent.grade < 0 || newStudent.grade > 100) {
        std::cout << "Invalid grade. Grade must be between 0 and 100." << std::endl;
        return;
    }

    students.push_back(newStudent);
}

void displayStudents(const std::vector<Student>& students) {
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << ", ID: " << student.id << ", Grade: " << student.grade << std::endl;
    }
}

void updateStudent(std::vector<Student>& students) {
    int idToUpdate;
    std::cout << "Enter the ID of the student to update: ";
    std::cin >> idToUpdate;

    auto it = std::find_if(students.begin(), students.end(), [idToUpdate](const Student& student) {
        return student.id == idToUpdate;
    });

    if (it != students.end()) {
        std::cout << "Enter new grade for the student: ";
        std::cin >> it->grade;
        std::cout << "Student record updated successfully." << std::endl;
    } else {
        std::cout << "Student with ID " << idToUpdate << " not found." << std::endl;
    }
}

void deleteStudent(std::vector<Student>& students) {
    int idToDelete;
    std::cout << "Enter the ID of the student to delete: ";
    std::cin >> idToDelete;

    auto it = std::remove_if(students.begin(), students.end(), [idToDelete](const Student& student) {
        return student.id == idToDelete;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "Student record deleted successfully." << std::endl;
    } else {
        std::cout << "Student with ID " << idToDelete << " not found." << std::endl;
    }
}

double calculateAverageGrade(const std::vector<Student>& students) {
    if (students.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (const Student& student : students) {
        sum += student.grade;
    }
    return sum / students.size();
}

void saveStudentsToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Student& student : students) {
            file << student.name << ' ' << student.id << ' ' << student.grade << '\n';
        }
        std::cout << "Student records saved to " << filename << " successfully." << std::endl;
    } else {
        std::cerr << "Error opening the file for saving." << std::endl;
    }
}

void loadStudentsFromFile(std::vector<Student>& students, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        Student student;
        while (file >> student.name >> student.id >> student.grade) {
            students.push_back(student);
        }
        std::cout << "Student records loaded from " << filename << " successfully." << std::endl;
    } else {
        std::cerr << "Error opening the file for loading." << std::endl;
    }
}

int main() {
    std::vector<Student> students;

    int choice;
    do {
        std::cout << "Menu:\n1. Add Student\n2. Update Student\n3. Delete Student\n4. Display Students\n5. Calculate Average Grade\n6. Save Students to File\n7. Load Students from File\n8. Quit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                updateStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                displayStudents(students);
                break;
            case 5:
                std::cout << "Average Grade: " << std::fixed << std::setprecision(2) << calculateAverageGrade(students) << std::endl;
                break;
            case 6:
                saveStudentsToFile(students, "student_records.txt");
                break;
            case 7:
                loadStudentsFromFile(students, "student_records.txt");
                break;
            case 8:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 8);

    return 0;
}
