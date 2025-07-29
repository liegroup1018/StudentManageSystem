#include "EnrollmentView.h"
#include "../utils/Validation.h"
#include <iostream>

int EnrollmentView::showEnrollmentMenu() {
    std::cout << "\n--- Enrollment Management ---\n";
    std::cout << "1. Enroll a student in a course\n";
    std::cout << "2. Unenroll a student from a course\n";
    std::cout << "3. View students enrolled in a specific course\n";
    std::cout << "4. View courses a specific student is enrolled in\n";
    std::cout << "5. Assign/update a grade for a student in a course\n";
    std::cout << "6. View grades for a specific student\n";
    std::cout << "7. View grades for a specific course\n";
    std::cout << "0. Back to Main Menu\n";
    return getIntegerInput("Enter your choice: ");
}

std::optional<std::string> EnrollmentView::getStudentIdInput() {
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

std::optional<std::string> EnrollmentView::getCourseIdInput() {
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

std::optional<int> EnrollmentView::getGradeInput() {
    while (true) {
        int grade = getIntegerInput("Enter the grade (0-100), or a negative number to cancel: ");
        if (grade < 0) {
            return std::nullopt;
        }
        if (Validation::isValidGrade(grade)) {
            return grade;
        }
        showMessage("Invalid grade. Must be between 0 and 100.");
    }
}

std::optional<std::string> EnrollmentView::getTermInput() {
    while (true) {
        std::string term = getStringInput("Enter the term (YYYY-S# e.g., 2024-S1), or 'cancel' to return: ");
        if (term == "cancel") {
            return std::nullopt;
        }
        if (Validation::isValidTerm(term)) {
            return term;
        }
        showMessage("Invalid term format. Required format: YYYY-S# (e.g., 2024-S1).");
    }
}

void EnrollmentView::displayStudentEnrollments(const Student& student, const std::vector<Course>& courses) {
    std::cout << "\n--- Courses for Student: " << student.getFullName() << " (" << student.getStudentId() << ") ---\n";
    if (courses.empty()) {
        showMessage("This student is not enrolled in any courses.");
        return;
    }
    for (const auto& course : courses) {
        std::cout << "- " << course.getCourseName() << " (" << course.getCourseCode() << ")\n";
    }
}

void EnrollmentView::displayCourseEnrollments(const Course& course, const std::vector<Student>& students) {
    std::cout << "\n--- Students in Course: " << course.getCourseName() << " (" << course.getCourseCode() << ") ---\n";
    if (students.empty()) {
        showMessage("No students are enrolled in this course.");
        return;
    }
    for (const auto& student : students) {
        std::cout << "- " << student.getFullName() << " (ID: " << student.getStudentId() << ")\n";
    }
}

void EnrollmentView::displayStudentEnrollmentsWithGrade(const Student& student, const std::vector<EnrollmentRecord>& enrollments) {
    std::cout << "\n--- Transcript for Student: " << student.getFullName() << " (" << student.getStudentId() << ") ---\n";
    if (enrollments.empty()) {
        showMessage("No enrollment records found for this student.");
        return;
    }
    for (const auto& record : enrollments) {
        std::cout << "Course ID: " << record.getCourseId()
                  << ", Term: " << record.getTerm()
                  << ", Grade: " << (record.getGrade() == -1 ? "Not Assigned" : std::to_string(record.getGrade())) << std::endl;
    }
}

void EnrollmentView::displayCourseEnrollmentsWithGrade(const Course& course, const std::vector<EnrollmentRecord>& enrollments) {
    std::cout << "\n--- Grades for Course: " << course.getCourseName() << " (" << course.getCourseCode() << ") ---\n";
    if (enrollments.empty()) {
        showMessage("No enrollment records found for this course.");
        return;
    }
    for (const auto& record : enrollments) {
        std::cout << "Student ID: " << record.getStudentId()
                  << ", Term: " << record.getTerm()
                  << ", Grade: " << (record.getGrade() == -1 ? "Not Assigned" : std::to_string(record.getGrade())) << std::endl;
    }
}
