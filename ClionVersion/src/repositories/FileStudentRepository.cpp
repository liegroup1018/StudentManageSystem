//
// Created by oulashu on 2025/7/9.
//

#include "FileStudentRepository.h"

Student FileStudentRepository::getStudent(const std::string &id) const {
    return Student();
}

void FileStudentRepository::deleteStudent(const std::string &id) {

}

void FileStudentRepository::updateStudent(const Student &student) {

}

std::vector<Student> FileStudentRepository::getAllStudents() const {
    return std::vector<Student>();
}

FileStudentRepository::FileStudentRepository(const std::string &filePath) : filePath(filePath) {}

void FileStudentRepository::loadData() {

}

void FileStudentRepository::saveData() {

}
