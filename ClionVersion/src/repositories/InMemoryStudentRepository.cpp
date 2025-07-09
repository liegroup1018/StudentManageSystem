//
// Created by oulashu on 2025/7/9.
//

#include "InMemoryStudentRepository.h"

Student InMemoryStudentRepository::getStudent(const std::string &id) const {
    auto it = students.find(id);
    if ( it != students.end()){
        return it->second;
    }

    throw StudentRepositotyError("Student with ID '" + id + "' not found.");
}

void InMemoryStudentRepository::deleteStudent(const std::string &id) {
    auto it = students.find(id);
    if ( it != students.end()){
        students.erase(it);
    }

    throw StudentRepositotyError("Cannot delete. Student with ID '" + id + "' not found.");
}

void InMemoryStudentRepository::updateStudent(const Student &student) {
    std::string id = student.getStudentId();
    auto it = students.find(id);
    if ( it != students.end()){
        students[id] = student;
    }

    throw StudentRepositotyError("Cannot update. Student with ID '" + id + "' not found.");
}

std::vector<Student> InMemoryStudentRepository::getAllStudents() const {
    std::vector<Student> s;
    if (!students.empty()){
        for(auto &it : students){
            s.push_back(it.second);
        }
        return std::move(s);
    }

    throw StudentRepositotyError("No students in memory");
}

