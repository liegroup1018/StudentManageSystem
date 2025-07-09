//
// Created by oulashu on 2025/7/9.
//

#ifndef CLIONVERSION_INMEMORYSTUDENTREPOSITORY_H
#define CLIONVERSION_INMEMORYSTUDENTREPOSITORY_H

#include "IStudentRepository.h"
#include <algorithm> // For std::find_if
#include <stdexcept> // For std::runtime_error
#include <unordered_map>
#include <string>

class InMemoryStudentRepository : public IStudentRepository{
public:
    Student getStudent(const std::string &id) const override;

    void deleteStudent(const std::string &id) override;

    void updateStudent(const Student &student) override;

    const std::vector<Student> &getAllStudents() const override;

private:
    std::unordered_map<std::string, Student> students;
};


#endif //CLIONVERSION_INMEMORYSTUDENTREPOSITORY_H
