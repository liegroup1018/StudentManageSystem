#pragma once

#include "../repositories/FileStudentRepository.h"
#include "../models/Student.h"
#include <string>
#include <vector>
#include <memory>

class StudentService
{
public:
    explicit StudentService(std::shared_ptr<FileStudentRepository> fsr);

	// Add a new student
	void addNewStudent(const Student& s);

	// View a student details
	Student searchAStudent(const std::string& sid);

	// Update a student details
	void updateAStudent(const Student& s);

	// Delete a student
	void deleteAStudent(const std::string& sid);

	// List all students
	std::vector<Student> searchAllStudents();

private:
	std::shared_ptr<FileStudentRepository> fsr;
};

