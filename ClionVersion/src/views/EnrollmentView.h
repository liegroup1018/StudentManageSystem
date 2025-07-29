#pragma once
#include "BaseView.h"
#include <vector>
#include <string>
#include <optional>

#include "../models/EnrollmentRecord.h"
#include "../models/Student.h"
#include "../models/Course.h"


class EnrollmentView : public BaseView
{
public:
    // --- Main Methods ---

    /* Displays the enrollment-specific submenu.
    * 1. Enroll a student in a course
    * 2. Unenroll a student from a course
    * 3. View students enrolled in a specific course
    * 4. View courses a specific student is enrolled in
    * 5. Assign/update a grade for a student in a course
    * 6. View grades for a specific student (transcript-like)
    * 7. View grades for a specific course (class performance)
    */
    int showEnrollmentMenu();

    // Prompts the user for a student ID and validates its format. Allows cancellation.
    std::optional<std::string> getStudentIdInput();

    // Prompts for a course ID and validates its format. Allows cancellation.
    std::optional<std::string> getCourseIdInput();

    //  Prompts for a grade and validates its format. Allows cancellation
    std::optional<int> getGradeInput();

    // Prompts for a term and validates its format. Allows cancellation.
    std::optional<std::string> getTermInput();

    // Displays a list of courses a student is enrolled in.
    void displayStudentEnrollments(const Student& student, const std::vector<Course>& courses);

    // Displays a list of students enrolled in a course.
    void displayCourseEnrollments(const Course& course, const std::vector<Student>& students);

    // Displays a list of courses a student is enrolled in and include grade.
    void displayStudentEnrollmentsWithGrade(const Student& student, const std::vector<EnrollmentRecord>& enrollment);

    // Displays a list of students enrolled in a course and include grade
    void displayCourseEnrollmentsWithGrade(const Course& course, const std::vector<EnrollmentRecord>& enrollment);
};

