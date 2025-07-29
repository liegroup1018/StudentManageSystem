#pragma once

#include "../repositories/FileCourseRepository.h"
#include "../models/Course.h"
#include <string>
#include <vector>
#include <memory>

class CourseService
{
public:
	explicit CourseService(std::shared_ptr<FileCourseRepository> fcr);

	// Add a new student
	void addNewCourse(const Course& s);

	// View a student details
	Course searchACourse(const std::string& sid);

	// Update a student details
	void updateACourse(const Course& s);

	// Delete a student
	void deleteACourse(const std::string& sid);

	// List all students
	std::vector<Course> searchAllCourses();
private:
	std::shared_ptr<FileCourseRepository> fcr;
};

