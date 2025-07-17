//
// Created by oulashu on 2025/7/17.
//

#include "FileEnrollmentRepository.h"

void FileEnrollmentRepository::addEnrollment(const EnrollmentRecord &e) {
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

void FileEnrollmentRepository::deleteEnrollment(const EnrollmentRecord &e) {
    std::string sid = e.getStudentId();
    std::string cid = e.getCourseId();

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

std::vector<std::string> FileEnrollmentRepository::getAllStudentsForACourse(const std::string &cid) {
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

std::vector<std::string> FileEnrollmentRepository::getAllCoursesForAStudent(const std::string &sid) {
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

int FileEnrollmentRepository::getGrade(const std::string &sid, const std::string &cid) {
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

std::unordered_map<std::string, int> FileEnrollmentRepository::getGradesForAStudent(const std::string &sid) {
    std::unordered_map<std::string, int> gc;
    for (const auto& e : enrollments) {
        if(e.getStudentId() == sid){
            gc[e.getCourseId()] = e.getGrade();
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

std::unordered_map<std::string, int> FileEnrollmentRepository::getGradesForACourse(const std::string &cid) {
    std::unordered_map<std::string, int> gs;
    for (const auto& e : enrollments) {
        if(e.getCourseId() == cid){
            gs[e.getStudentId()] = e.getGrade();
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

void FileEnrollmentRepository::assignGrade(const std::string &sid, const std::string &cid, int grade) {
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

bool FileEnrollmentRepository::containsEnrollment(const std::string &sid, const std::string &cid) {
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

FileEnrollmentRepository::FileEnrollmentRepository(std::string filepath) : filePath(filepath){
    loadData();
}

FileEnrollmentRepository::~FileEnrollmentRepository() {
    saveData();
}

void FileEnrollmentRepository::loadData() {
    std::ifstream f(filePath);
    if(!f){
        throw EnollmentRepositotyError("can not open: " + filePath + "!");
    }

    std::string buf;
    std::getline(f, buf);

    std::string studentId;
    std::string courseId;
    std::string term;
    std::string grade;

    while(getline(f,buf)){
        std::stringstream ss(buf);
        std::getline(ss, studentId, ',');
        std::getline(ss, courseId, ',');
        std::getline(ss, term, ',');
        std::getline(ss, grade, ',');
        EnrollmentRecord e{studentId, courseId, term};
        e.setGrade(std::stoi(grade));
        enrollments.push_back(e);
    }
    f.close();
}

void FileEnrollmentRepository::saveData() {
    std::ofstream f(filePath, std::ios::trunc);

    f << "StudentId," << "CourseId," << "Term," << "Grade" << "\n";

    for (const auto& e : enrollments){
        f << e.getStudentId() << ","
          << e.getCourseId() << ","
          << e.getTerm() << ","
          << e.getGrade() << "\n";
    }

    enrollments.clear();
    f.close();
}


