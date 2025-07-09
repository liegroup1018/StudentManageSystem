//
// Created by oulashu on 2025/7/9.
//

#ifndef CLIONVERSION_ISTUDENTREPOSITORY_H
#define CLIONVERSION_ISTUDENTREPOSITORY_H

#include "../models/Student.h"
#include <vector>

// The "Interface" for all student repositories.
// It defines the contract of what a repository can do, but not how it does it.
class IStudentRepository {
public:
    // A virtual destructor is essential for any class intended for polymorphic use.
    virtual ~IStudentRepository() = default;

    // --- Required Methods (The Contract) ---

    // Retrieves a single student by their ID.
    // Throws std::runtime_error if the student is not found.
    virtual Student getStudent(const std::string& id) const = 0;

    // Removes a student from the data source by their ID.
    // Throws std::runtime_error if the student is not found.
    virtual void deleteStudent(const std::string& id) = 0;

    // Modifies an existing student's data. Finds the student by student.studentId.
    // Throws std::runtime_error if the student to update is not found.
    virtual void updateStudent(const Student& student) = 0;

    // Retrieves a collection of all students.
    // Returns a const reference to avoid expensive copies.
    // Throws std::runtime_error if no student exists
    virtual const std::vector<Student>& getAllStudents() const = 0;

};

#endif //CLIONVERSION_ISTUDENTREPOSITORY_H
