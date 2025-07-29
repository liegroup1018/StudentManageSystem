//
// Created by oulashu on 2025/7/8.
//

#include "Course.h"

std::string Course::getCourseId() const {
    return courseId;
}

void Course::setCourseId(const std::string &courseId) {
    Course::courseId = courseId;
}

std::string Course::getCourseName() const {
    return courseName;
}

void Course::setCourseName(const std::string &courseName) {
    Course::courseName = courseName;
}

std::string Course::getCourseCode() const {
    return courseCode;
}

void Course::setCourseCode(const std::string &courseCode) {
    Course::courseCode = courseCode;
}

std::string Course::getDescription() const {
    return description;
}

void Course::setDescription(const std::string &description) {
    Course::description = description;
}

Course::Course(const std::string &id, const std::string &name,
               const std::string &code, const std::string &des)
    : courseId(id), courseName(name), courseCode(code), description(des)
{ }

bool operator==(const Course &lhs, const Course &rhs) {
    return lhs.courseId == rhs.courseId;
}
