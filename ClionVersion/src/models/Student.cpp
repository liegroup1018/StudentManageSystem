//
// Created by oulashu on 2025/7/8.
//

#include "Student.h"

std::string Student::getStudentId() const {
    return studentId;
}

void Student::setStudentId(const std::string &studentId) {
    Student::studentId = studentId;
}

std::string Student::getFullName() const {
    return fullName;
}

void Student::setFullName(const std::string &fullName) {
    Student::fullName = fullName;
}

int Student::getLevel() const {
    return level;
}

void Student::setLevel(int level) {
    Student::level = level;
}

Student::Student(const std::string &id, const std::string &name, int level)
    : studentId(id), fullName(name), level(level){}

bool operator==(const Student &lhs, const Student &rhs) {
    return lhs.studentId == rhs.studentId;
}
