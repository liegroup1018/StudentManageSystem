#pragma once
// --- Service Dependencies ---
#include "../services/StudentService.h"
#include "../services/CourseService.h"
#include "../services/EnrollmentService.h"

// --- View Dependencies ---
#include "../views/MainView.h"
#include "../views/StudentView.h"
#include "../views/CourseView.h"
#include "../views/EnrollmentView.h"

#include <memory>

// The AppController orchestrates the entire application.
// It responds to user input from the views by calling the appropriate services
// and then directs the views to display the results.
class AppController {
private:
    // --- Member Variables ---
    // References to all the dependencies the controller needs to function.
    std::shared_ptr<StudentService> studentService;
    std::shared_ptr<CourseService> courseService;
    std::shared_ptr<EnrollmentService> enrollmentService;

    std::shared_ptr<MainView> mainView;
    std::shared_ptr<StudentView> studentView;
    std::shared_ptr<CourseView> courseView;
    std::shared_ptr<EnrollmentView> enrollmentView;

public:
    // --- Constructor ---
    // Dependencies are injected via the constructor.
    AppController(
        std::shared_ptr<StudentService> ss, std::shared_ptr<CourseService> cs,
        std::shared_ptr<EnrollmentService> es, std::shared_ptr<MainView> mv,
        std::shared_ptr<StudentView> sv, std::shared_ptr<CourseView> cv,
        std::shared_ptr<EnrollmentView> ev);

    // --- Main Application Loop ---
    // This is the public entry point to start the application.
    void run();

private:
    // --- Private Handler Methods ---
    // Each handler manages a specific sub-menu of the application.
    void handleStudentMenu();
    void handleCourseMenu();
    void handleEnrollmentMenu();

     // --- Private Sub-handler Methods ---
    // These handle specific actions within a menu.

    // StudentView and StudentService
    void handleAddStudent();
    void handleFindStudent();
    void handleUpdateStudent();
    void handleDeleteStudent();
    void handleListAllStudent();

    // CourseView and CourseService
    void handleAddCourse();
    void handleFindCourse();
    void handleUpdateCourse();
    void handleDeleteCourse();
    void handleListAllCourse();

    // EnrollmentView and EnrollmentService
    void handleEnrollStudentInCourse();
    void handleUnEnrollStudentInCourse();
    void handleViewCoursesForStudent();
    void handleViewStudentsInCourse();
    void handleAssignGrade();
    void handleViewGradesForStudent();
    void handleViewGradesForCourse();
};

