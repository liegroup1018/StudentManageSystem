//
// Created by oulashu on 2025/7/8.
//

#include "EnrollmentRecord.h"

std::string EnrollmentRecord::getStudentId() const {
    return studentId;
}

void EnrollmentRecord::setStudentId(const std::string &studentId) {
    EnrollmentRecord::studentId = studentId;
}

std::string EnrollmentRecord::getCourseId() const {
    return courseId;
}

void EnrollmentRecord::setCourseId(const std::string &courseId) {
    EnrollmentRecord::courseId = courseId;
}

std::string EnrollmentRecord::getTerm() const {
    return term;
}

void EnrollmentRecord::setTerm(const std::string &term) {
    EnrollmentRecord::term = term;
}

int EnrollmentRecord::getGrade() const {
    return grade;
}

void EnrollmentRecord::setGrade(int grade) {
    EnrollmentRecord::grade = grade;
}

EnrollmentRecord::EnrollmentRecord(const std::string &sid, const std::string &cid,
                                   const std::string &term)
    : studentId(sid), courseId(cid), term(term) {}
