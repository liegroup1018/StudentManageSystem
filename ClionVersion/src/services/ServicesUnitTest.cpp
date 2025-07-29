#include "gtest/gtest.h"
#include "StudentService.h"
#include "CourseService.h"
#include "EnrollmentService.h"
//#include "../repositories/FileStudentRepository.h"
#include "../repositories/FileCourseRepository.h"
#include "../repositories/FileEnrollmentRepository.h"
#include "../utils/Validation.h"

class ServicesTest : public ::testing::Test {
protected:
    ServicesTest(){
        int* a = new int(8);
        student_repo = new FileStudentRepository("../src/test_data/students.csv");
        course_repo = new FileCourseRepository("../src/test_data/courses.csv");
        enrollment_repo = new FileEnrollmentRepository("../src/test_data/enrollments.csv");

        student_service = new StudentService(*student_repo);
        course_service = new CourseService(*course_repo);
        enrollment_service = new EnrollmentService(*enrollment_repo, *student_repo, *course_repo);
    }

    ~ServicesTest() {
        delete student_service;
        delete course_service;
        delete enrollment_service;
        delete student_repo;
        delete course_repo;
        delete enrollment_repo;
    }

    StudentService* student_service;
    CourseService* course_service;
    EnrollmentService* enrollment_service;
    FileStudentRepository* student_repo;
    FileCourseRepository* course_repo;
    FileEnrollmentRepository* enrollment_repo;
};

TEST_F(ServicesTest, GetStudent) {
    Student found_student = student_service->searchAStudent("S100001");
    ASSERT_EQ(found_student.getStudentId(), "S100001");
}

TEST_F(ServicesTest, GetCourse) {
    Course found_course = course_service->searchACourse("C100001");
    ASSERT_EQ(found_course.getCourseId(), "C100001");
}

TEST_F(ServicesTest, GetEnrollment) {
    auto courses = enrollment_service->findAllCoursesAStudentEnrolledIn("S100001");
    ASSERT_EQ(courses.size(), 2);
}

TEST_F(ServicesTest, GetStudentsForCourse) {
    auto students = enrollment_service->findAllStudentsForACourse("C100001");
    ASSERT_EQ(students.size(), 2);
}

TEST_F(ServicesTest, GetGradesForStudent) {
    auto records = enrollment_service->findGradesForAStudent("S100001");
    ASSERT_EQ(records.size(), 2);
}

TEST_F(ServicesTest, GetGradesForCourse) {
	auto records = enrollment_service->findGradesForACourse("C100001");
	ASSERT_EQ(records.size(), 2);
}

//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}