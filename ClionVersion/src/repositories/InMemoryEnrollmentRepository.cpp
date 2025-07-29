//
// Created by oulashu on 2025/7/14.
//

#include "InMemoryEnrollmentRepository.h"



void InMemoryEnrollmentRepository::addEnrollment(const EnrollmentRecord &e) {
    std::string sid = e.getStudentId();
    std::string cid = e.getCourseId();
    if (containsEnrollment(sid,cid)){
        throw EnollmentRepositotyError(
                "Enrollment with Student ID '" + sid + "' and Course ID '" + cid + "' already in.");
    }
    else{
        enrollments.push_back(e);
    }
}

void InMemoryEnrollmentRepository::deleteEnrollment(const std::string& sid, const std::string& cid) {
    
    auto exits = [&sid, &cid](EnrollmentRecord &e){
        return (e.getStudentId() == sid) && (e.getCourseId() == cid);
    };

    auto it  = std::remove_if(enrollments.begin(), enrollments.end(), exits);

    if (it == enrollments.end()){
        throw EnollmentRepositotyError(
                "Can not delete! Enrollment with Student ID '" +
                            sid + "' and Course ID '" + cid + "' not found.");
    }
    else{
        enrollments.erase(it, enrollments.end());
    }
}

std::vector<std::string> InMemoryEnrollmentRepository::getAllStudentsForACourse(const std::string &cid) {
    std::vector<std::string> s;
    for (const auto& e : enrollments) {
        if(e.getCourseId() == cid){
            s.push_back(e.getStudentId());
        }
    }

    if(s.empty()){
        throw EnollmentRepositotyError(
                "Enrollment with Course ID '" + cid + "' not found.");
    }
    else{
        return s;
    }
}

std::vector<std::string> InMemoryEnrollmentRepository::getAllCoursesForAStudent(const std::string &sid) {
    std::vector<std::string> c;
    for (const auto& e : enrollments) {
        if(e.getStudentId() == sid){
            c.push_back(e.getCourseId());
        }
    }

    if(c.empty()){
        throw EnollmentRepositotyError(
                "Enrollment with Student ID '" + sid + "' not found.");
    }
    else{
        return c;
    }
}

int InMemoryEnrollmentRepository::getGrade(const std::string &sid, const std::string &cid) {
    auto exits = [&sid, &cid](EnrollmentRecord &e){
        return (e.getStudentId() == sid) && (e.getCourseId() == cid);
    };

    auto it = std::find_if(enrollments.begin(), enrollments.end(), exits);

    if(it == enrollments.end()){
        throw EnollmentRepositotyError(
                "Enrollment with Student ID '" +
                sid + "' and Course ID '" + cid + "' not found.");
    }
    else {
        return it->getGrade();
    }
}

std::vector<EnrollmentRecord> InMemoryEnrollmentRepository::
                                    getGradesForAStudent(const std::string &sid)
{
    std::vector<EnrollmentRecord> gc;
    for (const auto& e : enrollments) {
        if(e.getStudentId() == sid){
            gc.push_back(e);
        }
    }

    if(gc.empty()){
        throw EnollmentRepositotyError(
                "Enrollment with Student ID '" + sid + "' not found.");
    }
    else{
        return gc;
    }
}

std::vector<EnrollmentRecord> InMemoryEnrollmentRepository::
                                    getGradesForACourse(const std::string &cid)
{
    std::vector<EnrollmentRecord> gs;
    for (const auto& e : enrollments) {
        if(e.getCourseId() == cid){
            gs.push_back(e);
        }
    }

    if(gs.empty()){
        throw EnollmentRepositotyError(
                "Enrollment with Student ID '" + cid + "' not found.");
    }
    else{
        return gs;
    }
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

void InMemoryEnrollmentRepository::assignGrade(const std::string &sid,
                                               const std::string &cid, int grade) {
    auto exits = [&sid, &cid](EnrollmentRecord &e){
        return (e.getStudentId() == sid) && (e.getCourseId() == cid);
    };

    auto it = std::find_if(enrollments.begin(), enrollments.end(), exits);

    if(it == enrollments.end()){
        throw EnollmentRepositotyError(
                "Enrollment with Student ID '" +
                sid + "' and Course ID '" + cid + "' not found.");
    }
    else {
        it->setGrade(grade);
    }
}
