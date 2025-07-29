#pragma once

#include "../repositories/FileEnrollmentRepository.h"
#include "../repositories/FileStudentRepository.h"
#include "../repositories/FileCourseRepository.h"
#include "../models/EnrollmentRecord.h"
#include "../models/Course.h"
#include "../models/Student.h"
#include <string>
#include <vector>
#include <memory>


class EnrollmentService
{
public:
	EnrollmentService(
            std::shared_ptr<FileEnrollmentRepository> fer,
            std::shared_ptr<FileStudentRepository> fsr,
            std::shared_ptr<FileCourseRepository> fcr);

	// Enroll a student in a course
	void enrollAStudent(const std::string& sid, const std::string& cid, const std::string& term);

	// Unenroll a student from a course
	void deleteAStudent(const std::string& sid, const std::string& cid);

	// View students enrolled in a specific course
	std::vector<Student> findAllStudentsForACourse(const std::string& cid);

	// View courses a specific student is enrolled in
	std::vector<Course> findAllCoursesAStudentEnrolledIn(const std::string& sid);

	// Assign/update a grade for a student in a course
	void assignGradeForAStudent(const std::string& sid, const std::string& cid, int grade);

	// View grades for a specific student (transcript-like)
	std::vector<EnrollmentRecord> findGradesForAStudent(const std::string& sid);

	// View grades for a specific course (class performance)
	std::vector<EnrollmentRecord> findGradesForACourse(const std::string& cid);

private:
	std::shared_ptr<FileEnrollmentRepository> fer;
    std::shared_ptr<FileStudentRepository> fsr;
    std::shared_ptr<FileCourseRepository> fcr;
};