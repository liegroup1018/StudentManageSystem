#include "AppController.h"
#include <iostream>

// --- Constructor Implementation ---
AppController::AppController(std::shared_ptr<StudentService> ss, std::shared_ptr<CourseService> cs,
                             std::shared_ptr<EnrollmentService> es, std::shared_ptr<MainView> mv,
                             std::shared_ptr<StudentView> sv, std::shared_ptr<CourseView> cv,
                             std::shared_ptr<EnrollmentView> ev):
studentService(ss), courseService(cs), enrollmentService(es), mainView(mv),
studentView(sv), courseView(cv),enrollmentView(ev)
{}

void AppController::run()
{
    bool running = true;
    while (running) {
        
        int choice = mainView->showMainMenu();
        std::cout << "showMainMenu() returned: " << choice << std::endl;
        switch (choice) {
        case 1: handleStudentMenu(); break;
        case 2: handleCourseMenu(); break;
        case 3: handleEnrollmentMenu(); break;
        case 0: running = false; break;
        default: mainView->showMessage("Invalid choice. Please try again.");
            mainView->waitForKeyPress();
            break;
        }
        mainView->clearScreen();
    }
    mainView->showMessage("Exiting application. Goodbye!");
}

void AppController::handleStudentMenu()
{
    bool inMenu = true;
    while (inMenu) {
        int choice = studentView->showStudentMenu();

        /*
         *  1. Add a new student
         *  2. View a student details (accroding to id)
         *  3. Update a student details
         *  4. Delete a student
         *  5. list all students 
         */
        switch (choice) {
        case 1: handleAddStudent(); break;
        case 2: handleFindStudent(); break;
        case 3: handleUpdateStudent(); break;
        case 4: handleDeleteStudent(); break;
        case 5: handleListAllStudent(); break;
        case 0: inMenu = false; break;
        default: studentView->showMessage("Invalid choice.");
            studentView->waitForKeyPress();
            break;
        }
    }
}

void AppController::handleCourseMenu()
{
    bool inMenu = true;
    while (inMenu) {
        int choice = courseView->showCourseMenu();
        switch (choice) {
        case 1: handleAddCourse(); break;
        case 2: handleFindCourse(); break;
        case 3: handleUpdateCourse(); break;
        case 4: handleDeleteCourse(); break;
        case 5: handleListAllCourse(); break;
        case 0: inMenu = false; break;
        default: courseView->showMessage("Invalid choice.");
            courseView->waitForKeyPress();
            break;
        }
    }
}


void AppController::handleEnrollmentMenu()
{
    bool inMenu = true;
    while (inMenu) {
        int choice = enrollmentView->showEnrollmentMenu();
        switch (choice) {
        case 1: handleEnrollStudentInCourse(); break;
        case 2: handleUnEnrollStudentInCourse(); break;
        case 3: handleViewStudentsInCourse(); break;
        case 4: handleViewCoursesForStudent(); break;
        case 5: handleAssignGrade(); break;
        case 6: handleViewGradesForStudent(); break;
        case 7: handleViewGradesForCourse(); break;
        case 0: inMenu = false; break;
        default: enrollmentView->showMessage("Invalid choice.");
            enrollmentView->waitForKeyPress();
            break;
        }
    }
}


// --- Action Sub-handlers ---


void AppController::handleAddStudent()
{
    auto studentOpt = studentView->getNewStudentInfo();
    if (!studentOpt) {
        studentView->showMessage("Add student operation cancelled.");
        studentView->waitForKeyPress();
        return;
    }

    try {
        studentService->addNewStudent(*studentOpt);
        studentView->showMessage("Student added successfully!");
    }
    catch (const std::runtime_error& e) {
        studentView->showMessage(e.what());
    }
    studentView->waitForKeyPress();
}

void AppController::handleFindStudent()
{
    auto studentIdOpt = studentView->getStudentIdInput();
    if (!studentIdOpt) {
        studentView->showMessage("Find student operation cancelled.");
        studentView->waitForKeyPress();
        return;
    }

    try {
        Student student = studentService->searchAStudent(*studentIdOpt);
        studentView->displayStudentDetails(student);
    }
    catch (const std::runtime_error& e) {
        studentView->showMessage(e.what());
    }
    studentView->waitForKeyPress();
}

void AppController::handleUpdateStudent()
{
    auto studentIdOpt = studentView->getStudentIdInput();
    if (!studentIdOpt) {
        studentView->showMessage("Update student operation cancelled.");
        studentView->waitForKeyPress();
        return;
    }

    try {

        auto studentOpt = studentView->getNewStudentInfo();
        if (!studentOpt) {
            studentView->showMessage("Update student operation cancelled.");
            studentView->waitForKeyPress();
            return;
        }

        studentService->updateAStudent(*studentOpt);
        studentView->showMessage("Student updated successfully!");
    }
    catch (const std::runtime_error& e) {
        studentView->showMessage(e.what());
    }
    studentView->waitForKeyPress();
}

void AppController::handleDeleteStudent()
{
    auto studentIdOpt = studentView->getStudentIdInput();
    if (!studentIdOpt) {
        studentView->showMessage("Delete student operation cancelled.");
        studentView->waitForKeyPress();
        return;
    }

    try {
        studentService->deleteAStudent(*studentIdOpt);
        studentView->showMessage("Student deleted successfully!");
    }
    catch (const std::runtime_error& e) {
        studentView->showMessage(e.what());
    }
    studentView->waitForKeyPress();
}

void AppController::handleListAllStudent()
{
    try {
        std::vector<Student> students = studentService->searchAllStudents();
        studentView->displayStudentList(students);
    }
    catch (const std::runtime_error& e) {
        studentView->showMessage(e.what());
    }
    studentView->waitForKeyPress();
}

// --- Course Handlers ---

void AppController::handleAddCourse()
{
    auto courseOpt = courseView->getNewCourseInfo();
    if (!courseOpt) {
        courseView->showMessage("Add course operation cancelled.");
        courseView->waitForKeyPress();
        return;
    }

    try {
        courseService->addNewCourse(*courseOpt);
        courseView->showMessage("Course added successfully!");
    }
    catch (const std::runtime_error& e) {
        courseView->showMessage(e.what());
    }
    courseView->waitForKeyPress();
}

void AppController::handleFindCourse()
{
    auto courseIdOpt = courseView->getCourseIdInput();
    if (!courseIdOpt) {
        courseView->showMessage("Find course operation cancelled.");
        courseView->waitForKeyPress();
        return;
    }

    try {
        Course course = courseService->searchACourse(*courseIdOpt);
        courseView->displayCourseDetails(course);
    }
    catch (const std::runtime_error& e) {
        courseView->showMessage(e.what());
    }
    courseView->waitForKeyPress();
}

void AppController::handleUpdateCourse()
{
    auto courseIdOpt = courseView->getCourseIdInput();
    if (!courseIdOpt) {
        courseView->showMessage("Update course operation cancelled.");
        courseView->waitForKeyPress();
        return;
    }

    try {
        auto courseOpt = courseView->getNewCourseInfo();
        if (!courseOpt) {
            courseView->showMessage("Update course operation cancelled.");
            courseView->waitForKeyPress();
            return;
        }

        courseService->updateACourse(*courseOpt);
        courseView->showMessage("Course updated successfully!");
    }
    catch (const std::runtime_error& e) {
        courseView->showMessage(e.what());
    }
    courseView->waitForKeyPress();
}

void AppController::handleDeleteCourse()
{
    auto courseIdOpt = courseView->getCourseIdInput();
    if (!courseIdOpt) {
        courseView->showMessage("Delete course operation cancelled.");
        courseView->waitForKeyPress();
        return;
    }

    try {
        courseService->deleteACourse(*courseIdOpt);
        courseView->showMessage("Course deleted successfully!");
    }
    catch (const std::runtime_error& e) {
        courseView->showMessage(e.what());
    }
    courseView->waitForKeyPress();
}

void AppController::handleListAllCourse()
{
    try {
        std::vector<Course> courses = courseService->searchAllCourses();
        courseView->displayCourseList(courses);
    }
    catch (const std::runtime_error& e) {
        courseView->showMessage(e.what());
    }
    courseView->waitForKeyPress();
}

// --- Enrollment Handlers ---

void AppController::handleEnrollStudentInCourse()
{
    auto studentIdOpt = enrollmentView->getStudentIdInput();
    if (!studentIdOpt) {
        enrollmentView->showMessage("Enrollment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    auto courseIdOpt = enrollmentView->getCourseIdInput();
    if (!courseIdOpt) {
        enrollmentView->showMessage("Enrollment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    auto termOpt = enrollmentView->getTermInput();
    if (!termOpt) {
        enrollmentView->showMessage("Enrollment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    try {
        enrollmentService->enrollAStudent(*studentIdOpt, *courseIdOpt, *termOpt);
        enrollmentView->showMessage("Student enrolled successfully!");
    }
    catch (const std::runtime_error& e) {
        enrollmentView->showMessage(e.what());
    }
    enrollmentView->waitForKeyPress();
}

void AppController::handleUnEnrollStudentInCourse()
{
    auto studentIdOpt = enrollmentView->getStudentIdInput();
    if (!studentIdOpt) {
        enrollmentView->showMessage("Unenrollment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    auto courseIdOpt = enrollmentView->getCourseIdInput();
    if (!courseIdOpt) {
        enrollmentView->showMessage("Unenrollment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    try {
        enrollmentService->deleteAStudent(*studentIdOpt, *courseIdOpt);
        enrollmentView->showMessage("Student unenrolled successfully!");
    }
    catch (const std::runtime_error& e) {
        enrollmentView->showMessage(e.what());
    }
    enrollmentView->waitForKeyPress();
}

void AppController::handleViewCoursesForStudent()
{
    auto studentIdOpt = enrollmentView->getStudentIdInput();
    if (!studentIdOpt) {
        enrollmentView->showMessage("Operation cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    try {
        Student student = studentService->searchAStudent(*studentIdOpt);
        std::vector<Course> courses = enrollmentService->findAllCoursesAStudentEnrolledIn(*studentIdOpt);
        enrollmentView->displayStudentEnrollments(student, courses);
    }
    catch (const std::runtime_error& e) {
        enrollmentView->showMessage(e.what());
    }
    enrollmentView->waitForKeyPress();
}

void AppController::handleViewStudentsInCourse()
{
    auto courseIdOpt = enrollmentView->getCourseIdInput();
    if (!courseIdOpt) {
        enrollmentView->showMessage("Operation cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    try {
        Course course = courseService->searchACourse(*courseIdOpt);
        std::vector<Student> students = enrollmentService->findAllStudentsForACourse(*courseIdOpt);
        enrollmentView->displayCourseEnrollments(course, students);
    }
    catch (const std::runtime_error& e) {
        enrollmentView->showMessage(e.what());
    }
    enrollmentView->waitForKeyPress();
}

void AppController::handleAssignGrade()
{
    auto studentIdOpt = enrollmentView->getStudentIdInput();
    if (!studentIdOpt) {
        enrollmentView->showMessage("Grade assignment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    auto courseIdOpt = enrollmentView->getCourseIdInput();
    if (!courseIdOpt) {
        enrollmentView->showMessage("Grade assignment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    auto gradeOpt = enrollmentView->getGradeInput();
    if (!gradeOpt) {
        enrollmentView->showMessage("Grade assignment cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    try {
        enrollmentService->assignGradeForAStudent(*studentIdOpt, *courseIdOpt, *gradeOpt);
        enrollmentView->showMessage("Grade assigned successfully!");
    }
    catch (const std::runtime_error& e) {
        enrollmentView->showMessage(e.what());
    }
    enrollmentView->waitForKeyPress();
}

void AppController::handleViewGradesForStudent()
{
    auto studentIdOpt = enrollmentView->getStudentIdInput();
    if (!studentIdOpt) {
        enrollmentView->showMessage("Operation cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    try {
        Student student = studentService->searchAStudent(*studentIdOpt);
        std::vector<EnrollmentRecord> records = enrollmentService->findGradesForAStudent(*studentIdOpt);
        enrollmentView->displayStudentEnrollmentsWithGrade(student, records);
    }
    catch (const std::runtime_error& e) {
        enrollmentView->showMessage(e.what());
    }
    enrollmentView->waitForKeyPress();
}

void AppController::handleViewGradesForCourse()
{
    auto courseIdOpt = enrollmentView->getCourseIdInput();
    if (!courseIdOpt) {
        enrollmentView->showMessage("Operation cancelled.");
        enrollmentView->waitForKeyPress();
        return;
    }

    try {
        Course course = courseService->searchACourse(*courseIdOpt);
        std::vector<EnrollmentRecord> records = enrollmentService->findGradesForACourse(*courseIdOpt);
        enrollmentView->displayCourseEnrollmentsWithGrade(course, records);
    }
    catch (const std::runtime_error& e) {
        enrollmentView->showMessage(e.what());
    }
    enrollmentView->waitForKeyPress();
}




