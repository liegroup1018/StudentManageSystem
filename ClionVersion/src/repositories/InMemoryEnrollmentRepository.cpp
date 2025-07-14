//
// Created by oulashu on 2025/7/14.
//

#include "InMemoryEnrollmentRepository.h"
#include <algorithm>


void InMemoryEnrollmentRepository::addEnrollment(const EnrollmentRecord &e) {
    std::string sid = e.getStudentId();
    std::string cid = e.getCourseId();
    if (containsEnrollment(sid,cid)){
        throw EnollmentRepositotyError(
                "Enrollment with Student ID '" + sid + "' and CourseID '" + cid + "' not found.");
    }
    else{
        enrollments.push_back(e);
    }
}

void InMemoryEnrollmentRepository::deleteEnrollment(const EnrollmentRecord &e) {

}

std::vector<std::string> InMemoryEnrollmentRepository::getAllStudentsForACourse(const std::string &cid) {
    return std::vector<std::string>();
}

std::vector<std::string> InMemoryEnrollmentRepository::getAllCoursesForAStudent(const std::string &sid) {
    return std::vector<std::string>();
}

void InMemoryEnrollmentRepository::saveGrade(const std::string &sid, const std::string &cid, int grade) {

}

std::unordered_map<std::string, int> InMemoryEnrollmentRepository::getGradesForAStudent(const std::string &sid) {
    return std::unordered_map<std::string, int>();
}

std::unordered_map<std::string, int> InMemoryEnrollmentRepository::getGradesForACourse(const std::string &cid) {
    return std::unordered_map<std::string, int>();
}

bool InMemoryEnrollmentRepository::containsEnrollment(const std::string &sid, const std::string &cid) {
    auto exits = [&sid, &cid](EnrollmentRecord &e){
        return (e.getStudentId() == sid) && (e.getCourseId() == cid);
    };

    auto it = std::find_if(enrollments.begin(), enrollments.end(), exits);

    if(it == enrollments.end()){
        return false;
    }
    else {
        return true;
    }
}
