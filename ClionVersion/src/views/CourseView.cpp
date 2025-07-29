#include "CourseView.h"
#include "../utils/Validation.h"
#include <iostream>

int CourseView::showCourseMenu() {
    std::cout << "\n--- Course Management ---\n";
    std::cout << "1. Add a new course\n";
    std::cout << "2. View a course details\n";
    std::cout << "3. Update a course details\n";
    std::cout << "4. Delete a course\n";
    std::cout << "5. List all courses\n";
    std::cout << "0. Back to Main Menu\n";
    return getIntegerInput("Enter your choice: ");
}

void CourseView::displayCourseList(const std::vector<Course>& courses) {
    if (courses.empty()) {
        showMessage("No courses found.");
        return;
    }
    std::cout << "\n--- Course List ---\n";
    for (const auto& course : courses) {
        std::cout << "ID: " << course.getCourseId()
                  << ", Name: " << course.getCourseName()
                  << ", Code: " << course.getCourseCode() << std::endl;
    }
}

void CourseView::displayCourseDetails(const Course& course) {
    std::cout << "\n--- Course Details ---\n";
    std::cout << "ID:          " << course.getCourseId() << std::endl;
    std::cout << "Name:        " << course.getCourseName() << std::endl;
    std::cout << "Code:        " << course.getCourseCode() << std::endl;
    std::cout << "Description: " << course.getDescription() << std::endl;
}

std::optional<std::string> CourseView::getCourseIdInput() {
    while (true) {
        std::string id = getStringInput("Enter the course ID (or type 'cancel' to return): ");
        if (id == "cancel") {
            return std::nullopt;
        }
        if (Validation::isValidCourseId(id)) {
            return id;
        }
        showMessage("Invalid Course ID format. Must be C followed by 6 digits (e.g., C123456).");
    }
}

std::optional<Course> CourseView::getNewCourseInfo() {
    showMessage("Enter new course details. Type 'cancel' at any prompt to abort.");

    auto idOpt = getCourseIdInput();
    if (!idOpt) return std::nullopt;

    std::string name = getStringInput("Enter Course Name: ");
    if (name == "cancel") return std::nullopt;

    std::string code = getStringInput("Enter Course Code: ");
    if (code == "cancel") return std::nullopt;

    std::string description = getStringInput("Enter Description: ");
    if (description == "cancel") return std::nullopt;

    return Course(*idOpt, name, code, description);
}
