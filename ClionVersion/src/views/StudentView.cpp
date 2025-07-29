#include "StudentView.h"
#include "../utils/Validation.h"
#include <iostream>

int StudentView::showStudentMenu() {
    std::cout << "\n--- Student Management ---\n";
    std::cout << "1. Add a new student\n";
    std::cout << "2. View a student details\n";
    std::cout << "3. Update a student details\n";
    std::cout << "4. Delete a student\n";
    std::cout << "5. List all students\n";
    std::cout << "0. Back to Main Menu\n";
    return getIntegerInput("Enter your choice: ");
}

void StudentView::displayStudentList(const std::vector<Student>& students) {
    if (students.empty()) {
        showMessage("No students found.");
        return;
    }
    std::cout << "\n--- Student List ---\n";
    for (const auto& student : students) {
        std::cout << "ID: " << student.getStudentId()
                  << ", Name: " << student.getFullName()
                  << ", Level: " << student.getLevel() << std::endl;
    }
}

void StudentView::displayStudentDetails(const Student& student) {
    std::cout << "\n--- Student Details ---\n";
    std::cout << "ID:        " << student.getStudentId() << std::endl;
    std::cout << "Full Name: " << student.getFullName() << std::endl;
    std::cout << "Level:     " << student.getLevel() << std::endl;
}

std::optional<std::string> StudentView::getStudentIdInput() {
    while (true) {
        std::string id = getStringInput("Enter the student ID (or type 'cancel' to return): ");
        if (id == "cancel") {
            return std::nullopt;
        }
        if (Validation::isValidStudentId(id)) {
            return id;
        }
        showMessage("Invalid Student ID format. Must be S followed by 6 digits (e.g., S123456).");
    }
}

std::optional<Student> StudentView::getNewStudentInfo() {
    showMessage("Enter new student details. Type 'cancel' at any prompt to abort.");

    auto idOpt = getStudentIdInput();
    if (!idOpt) return std::nullopt;

    std::string name = getStringInput("Enter Full Name: ");
    if (name == "cancel") return std::nullopt;

    int level = getIntegerInput("Enter Level  or a negative number to cancel: ");
    if (level < 0) return std::nullopt;

    return Student(*idOpt, name, level);
}
