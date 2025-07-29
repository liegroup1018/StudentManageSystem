#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "AppController.h"
#include "../services/StudentService.h"
#include "../services/CourseService.h"
#include "../services/EnrollmentService.h"
#include "../repositories/FileStudentRepository.h"
#include "../repositories/FileCourseRepository.h"
#include "../repositories/FileEnrollmentRepository.h"
#include "../views/MainView.h"
#include "../views/StudentView.h"
#include "../views/CourseView.h"
#include "../views/EnrollmentView.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

#include <memory>

// --- Mock View Classes ---

class MockMainView : public MainView {
public:
    MOCK_METHOD(void, clearScreen, (), (const, override));
    MOCK_METHOD(void, showMessage, (const std::string& message), (const));
    MOCK_METHOD(void, waitForKeyPress, (), (const, override));
    MOCK_METHOD(std::string, getStringInput, (const std::string& prompt), (const, override));
    MOCK_METHOD(int, getIntegerInput, (const std::string& prompt), (const, override));
};

class MockStudentView : public StudentView {
public:
    MOCK_METHOD(void, clearScreen, (), (const, override));
    MOCK_METHOD(void, showMessage, (const std::string& message), (const));
    MOCK_METHOD(void, waitForKeyPress, (), (const, override));
    MOCK_METHOD(std::string, getStringInput, (const std::string& prompt), (const, override));
    MOCK_METHOD(int, getIntegerInput, (const std::string& prompt), (const, override));
    MOCK_METHOD(void, displayStudentDetails, (const Student& student), (const));
};

class MockCourseView : public CourseView {
public:
    MOCK_METHOD(void, clearScreen, (), (const, override));
    MOCK_METHOD(void, showMessage, (const std::string& message), (const));
    MOCK_METHOD(void, waitForKeyPress, (), (const, override));
    MOCK_METHOD(std::string, getStringInput, (const std::string& prompt), (const, override));
    MOCK_METHOD(int, getIntegerInput, (const std::string& prompt), (const, override));
};

class MockEnrollmentView : public EnrollmentView {
public:
    MOCK_METHOD(void, clearScreen, (), (const, override));
    MOCK_METHOD(void, showMessage, (const std::string& message), (const, override));
    MOCK_METHOD(void, waitForKeyPress, (), (const, override));
    MOCK_METHOD(std::string, getStringInput, (const std::string& prompt), (const, override));
    MOCK_METHOD(int, getIntegerInput, (const std::string& prompt), (const, override));
};

// --- Test Fixture ---

class AppControllerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup repositories with test data
        studentRepo
            = std::make_shared<FileStudentRepository>("../src/test_data/students.csv");
        courseRepo
            = std::make_shared<FileCourseRepository>("../src/test_data/courses.csv");
        enrollmentRepo
            = std::make_shared<FileEnrollmentRepository>("../src/test_data/enrollments.csv");

        // Setup services
        std::shared_ptr<StudentService> studentService
            = std::make_shared<StudentService>(studentRepo);
        std::shared_ptr<CourseService> courseService
            = std::make_shared<CourseService>(courseRepo);
        std::shared_ptr<EnrollmentService> enrollmentService
            = std::make_shared<EnrollmentService>
                        (enrollmentRepo, studentRepo, courseRepo);

        // Setup mock views
        mockMainView = std::make_shared<MockMainView>();
        mockStudentView = std::make_shared<MockStudentView>();
        mockCourseView = std::make_shared<MockCourseView>();
        mockEnrollmentView = std::make_shared<MockEnrollmentView>();

        // Setup controller
        controller = std::make_shared<AppController>(
            studentService, courseService, enrollmentService,
            mockMainView, mockStudentView, mockCourseView,
            mockEnrollmentView);
    }

    void TearDown() override {

    }

    std::shared_ptr<FileStudentRepository> studentRepo;
    std::shared_ptr<FileCourseRepository> courseRepo;
    std::shared_ptr<FileEnrollmentRepository> enrollmentRepo;
    std::shared_ptr<MockMainView> mockMainView;
    std::shared_ptr<MockStudentView> mockStudentView;
    std::shared_ptr<MockCourseView> mockCourseView;
    std::shared_ptr<MockEnrollmentView> mockEnrollmentView;
    std::shared_ptr<AppController> controller;
    
};

// --- Test Cases ---

TEST_F(AppControllerTest, HandleAddStudentSuccessfully) {
    // Simulate user navigation: Main Menu -> Student Menu -> Add Student -> Back -> Exit
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
        .WillOnce(Return(1)) // Select Student Menu
        .WillOnce(Return(0)); // Exit

    // switch to Student Menu, reading user input
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter your choice: "))
        .WillOnce(Return(1)) // Select Add Student
        .WillOnce(Return(0)); // Back to Main Menu

    // Simulate user input for a new student
    std::string studentid = "S999999";
    std::string fullname = "Test User";
    int level = 1;
    EXPECT_CALL(*mockStudentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
        .WillOnce(Return(studentid));
    EXPECT_CALL(*mockStudentView, getStringInput("Enter Full Name: "))
            .WillOnce(Return(fullname));
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter Level  or a negative number to cancel: "))
            .WillOnce(Return(level));

    // Expect success message
    EXPECT_CALL(*mockStudentView, showMessage("Enter new student details. Type 'cancel' at any prompt to abort."))
            .Times(AtLeast(1));
    EXPECT_CALL(*mockStudentView, showMessage("Student added successfully!"))
        .Times(AtLeast(1));
    EXPECT_CALL(*mockStudentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}

TEST_F(AppControllerTest, HandleFindStudentAndDisplayDetails) {
    // Simulate user navigation: Main Menu -> Student Menu -> View Student -> Back -> Exit

    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
        .WillOnce(Return(1)) // Select Student Menu
        .WillOnce(Return(0)); // Exit

    // showStudentView
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter your choice: "))
        .WillOnce(Return(2)) // Select View Student
        .WillOnce(Return(0)); // Back to Main Menu

    // Simulate user providing an existing student ID
    // handleFindStudent() -> getStudentIdInput()
    std::string existingId = "S100001";
    EXPECT_CALL(*mockStudentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
        .WillOnce(Return(existingId));

    // Expect the controller to call displayStudentDetails with the correct student
//    Student expectedStudent = studentRepo->getStudent(existingId);
//    EXPECT_CALL(*mockStudentView, displayStudentDetails(expectedStudent))
//        .Times(1);
    EXPECT_CALL(*mockStudentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleAddStudentCancelled) {
    // Simulate user navigation: Main Menu -> Student Menu -> Add Student (and cancels) -> Back -> Exit

    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Select Student Menu
            .WillOnce(Return(0)); // Exit

    // showStudentView
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Select Add Student
            .WillOnce(Return(0)); // Back to Main Menu

    // Simulate user cancelling the operation
    // handleStudentMenu() -> handleAddStudent() ->
    // studentView->getNewStudentInfo() --> getStudentIdInput()
    std::string input = "cancel";
    EXPECT_CALL(*mockStudentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
        .WillOnce(Return(input));

    // Expect cancellation message
    EXPECT_CALL(*mockStudentView, showMessage(_));
    EXPECT_CALL(*mockStudentView, showMessage("Add student operation cancelled."))
        .Times(1);
    EXPECT_CALL(*mockStudentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleUpdateStudentSuccessfully) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Select Student Menu
            .WillOnce(Return(0)); // Exit


    // showStudentView
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Update Student
            .WillOnce(Return(0)); // Back to Main Menu

    std::string studentId = "S100001";
    std::string name = "Updated Name";
    int level = 4;

    /*
     * handleStudentMenu() --> handleUpdateStudent() -->
     * StudentView::getNewStudentInfo()
     * */
    EXPECT_CALL(*mockStudentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
            .WillOnce(Return(studentId));
    EXPECT_CALL(*mockStudentView, getStringInput("Enter Full Name: "))
            .WillOnce(Return(name));
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter Level  or a negative number to cancel: "))
            .WillOnce(Return(level));

    // Expect cancellation message
    EXPECT_CALL(*mockStudentView, showMessage(_));
    EXPECT_CALL(*mockStudentView, showMessage("Student updated successfully!")).Times(1);
    EXPECT_CALL(*mockStudentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleDeleteStudentSuccessfully) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Select Student Menu
            .WillOnce(Return(0)); // Exit

    // showStudentView
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(4)) // Delete Student
            .WillOnce(Return(0)); // Back to Main Menu

    std::string studentId = "S100002";
    /*
    * handleStudentMenu() --> handleDeleteStudent() -->
    * StudentView::getStudentIdInput()
    * */
    EXPECT_CALL(*mockStudentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
            .WillOnce(Return(studentId));

    // Expect cancellation message
    EXPECT_CALL(*mockStudentView, showMessage("Student deleted successfully!")).Times(1);
    EXPECT_CALL(*mockStudentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleListAllStudents) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Select Student Menu
            .WillOnce(Return(0)); // Exit

    // showStudentView
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(5)) // Display all Students
            .WillOnce(Return(0)); // Back to Main Menu

    /*
    * handleStudentMenu() --> handleListAllStudent() -->
    * */
    EXPECT_CALL(*mockStudentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleAddCourseSuccessfully) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(2)) // Select Course Menu
            .WillOnce(Return(0)); // Exit

    // showCourseView
    EXPECT_CALL(*mockCourseView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Add New Course
            .WillOnce(Return(0)); // Back to Main Menu

    /*
     * handleCourseMenu() -> handleAddCourse() -> CourseView::getNewCourseInfo()
     * */
    Course newCourse("C999999", "New Course", "NC101", "A new test course");
    std::string courseid = "C999999";
    std::string courseName =  "New Course";
    std::string courseCode = "NC101";
    std::string courseDescription = "A new test course";
    EXPECT_CALL(*mockCourseView, getStringInput("Enter the course ID (or type 'cancel' to return): "))
        .WillOnce(Return(courseid));
    EXPECT_CALL(*mockCourseView, getStringInput("Enter Course Name: "))
            .WillOnce(Return(courseName));
    EXPECT_CALL(*mockCourseView, getStringInput("Enter Course Code: "))
            .WillOnce(Return(courseCode));
    EXPECT_CALL(*mockCourseView, getStringInput("Enter Description: "))
            .WillOnce(Return(courseDescription));


    // expected message
    EXPECT_CALL(*mockCourseView, showMessage(_));
    EXPECT_CALL(*mockCourseView, showMessage("Course added successfully!")).Times(1);
    EXPECT_CALL(*mockCourseView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleEnrollStudentSuccessfully) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Enrollment Menu
            .WillOnce(Return(0)); // Exit

    // showEnrollmentView
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Enroll a Student
            .WillOnce(Return(0)); // Back to Main Menu

    /*
     * handleEnrollmentMenu() -> handleEnrollStudentInCourse()
     * */
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
        .WillOnce(Return("S100003"));
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the course ID (or type 'cancel' to return): "))
        .WillOnce(Return("C100003"));
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the term (YYYY-S# e.g., 2024-S1), or 'cancel' to return: "))
        .WillOnce(Return("2024-S2"));

    // expected message
    EXPECT_CALL(*mockEnrollmentView, showMessage("Student enrolled successfully!")).Times(1);
    EXPECT_CALL(*mockEnrollmentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleAssignGradeSuccessfully) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Enrollment Menu
            .WillOnce(Return(0)); // Exit

    // showEnrollmentView
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(5)) // Assign a grade
            .WillOnce(Return(0)); // Back to Main Menu

    /*
     * handleEnrollmentMenu() -> handleAssignGrade()
     * */
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
            .WillOnce(Return("S100001"));
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the course ID (or type 'cancel' to return): "))
            .WillOnce(Return("C100001"));
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter the grade (0-100), or a negative number to cancel: "))
            .WillOnce(Return(95));

    // expected message
    EXPECT_CALL(*mockEnrollmentView, showMessage("Grade assigned successfully!")).Times(1);
    EXPECT_CALL(*mockEnrollmentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleFindCourseSuccessfully) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(2)) // Select Course Menu
            .WillOnce(Return(0)); // Exit

    // showCourseView
    EXPECT_CALL(*mockCourseView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(2)) // Find a Course
            .WillOnce(Return(0)); // Back to Main Menu

    /*
     * handleCourseMenu() -> handleFindCourse() -> CourseView::getCourseIdInput()
     * */
    std::string courseId = "C100001";
    EXPECT_CALL(*mockCourseView, getStringInput("Enter the course ID (or type 'cancel' to return): "))
            .WillOnce(Return(courseId));

    // Expected result
    EXPECT_CALL(*mockCourseView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleListAllCourses) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(2)) // Select Course Menu
            .WillOnce(Return(0)); // Exit

    // showCourseView
    EXPECT_CALL(*mockCourseView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(5)) // list all courses
            .WillOnce(Return(0)); // Back to Main Menu

    EXPECT_CALL(*mockCourseView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleUnenrollStudentSuccessfully) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Enrollment Menu
            .WillOnce(Return(0)); // Exit

    // showEnrollmentView
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(2)) // Unenroll
            .WillOnce(Return(0)); // Back to Main Menu

    /*
     * handleEnrollmentMenu() -> handleUnEnrollStudentInCourse()
     * -> EnrollmentView::getStudentIdInput() -> EnrollmentView::getCourseIdInput()
     * */
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
            .WillOnce(Return("S100001"));
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the course ID (or type 'cancel' to return): "))
            .WillOnce(Return("C100001"));

    // expected message
    EXPECT_CALL(*mockEnrollmentView, showMessage("Student unenrolled successfully!")).Times(1);
    EXPECT_CALL(*mockEnrollmentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleViewStudentsInCourse) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Enrollment Menu
            .WillOnce(Return(0)); // Exit

    // showEnrollmentView
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // View Students
            .WillOnce(Return(0)); // Back to Main Menu

    /*
    * handleEnrollmentMenu() -> handleViewStudentsInCourse()
    * -> EnrollmentView::getCourseIdInput()
    * */
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the course ID (or type 'cancel' to return): "))
            .WillOnce(Return("C100001"));

    // expected message
    EXPECT_CALL(*mockEnrollmentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleViewCoursesForStudent) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Enrollment Menu
            .WillOnce(Return(0)); // Exit

    // showEnrollmentView
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(4)) // View Courses
            .WillOnce(Return(0)); // Back to Main Menu

    /*
    * handleEnrollmentMenu() -> handleViewStudentsInCourse()
    * -> EnrollmentView::getStudentIdInput()
    * */
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
            .WillOnce(Return("S100001"));

    EXPECT_CALL(*mockEnrollmentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleViewGradesForStudent) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Enrollment Menu
            .WillOnce(Return(0)); // Exit

    // showEnrollmentView
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(6)) // View Grades
            .WillOnce(Return(0)); // Back to Main Menu

    /*
    * handleEnrollmentMenu() -> handleViewGradesForStudent()
    * -> EnrollmentView::getStudentIdInput()
    * */
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
            .WillOnce(Return("S100001"));

    EXPECT_CALL(*mockEnrollmentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleViewGradesForCourse) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(3)) // Select Enrollment Menu
            .WillOnce(Return(0)); // Exit

    // showEnrollmentView
    EXPECT_CALL(*mockEnrollmentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(7)) // View Grades for courses
            .WillOnce(Return(0)); // Back to Main Menu

    /*
    * handleEnrollmentMenu() -> handleViewGradesForCourse()
    * -> EnrollmentView::getCourseIdInput()
    * */
    EXPECT_CALL(*mockEnrollmentView, getStringInput("Enter the course ID (or type 'cancel' to return): "))
            .WillOnce(Return("C100001"));

    EXPECT_CALL(*mockEnrollmentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}
//
TEST_F(AppControllerTest, HandleFindStudentNotFound) {
    // showMainView
    EXPECT_CALL(*mockMainView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(1)) // Select Student Menu
            .WillOnce(Return(0)); // Exit

    // showStudentView
    EXPECT_CALL(*mockStudentView, getIntegerInput("Enter your choice: "))
            .WillOnce(Return(2)) // Select View Student
            .WillOnce(Return(0)); // Back to Main Menu


    std::string nonExistentId = "S000000";

    /*
     * handleStudentMenu() -> handleFindStudent() -> StudentView::getStudentIdInput()
     * */
    EXPECT_CALL(*mockStudentView, getStringInput("Enter the student ID (or type 'cancel' to return): "))
            .WillOnce(Return(nonExistentId));


    EXPECT_CALL(*mockStudentView, showMessage("Student with ID 'S000000' not found."))
        .Times(1);
    EXPECT_CALL(*mockStudentView, waitForKeyPress()).Times(AtLeast(1));

    controller->run();
}

//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
