//
// Created by oulashu on 2025/7/11.
//
#include "gtest/gtest.h"
#include "IStudentRepository.h"
#include "FileStudentRepository.h"
#include "InMemoryStudentRepository.h"
#include "ICourseRepository.h"
#include "FileCourseRepository.h"
#include "InMemoryCourseRepository.h"

/******************* StudentInMemoryRepositoryTest**********************/
///*
// * 系统中没有任何学生信息，添加新的学生信息
// */
//TEST(AddAndContainStudentTest, AddNotExit){
//    InMemoryStudentRepository r;
//    r.addStudent(Student{"S039482","James Smith",3});
//
//    bool exit = r.containStudent("S039482");
//    bool notexit = r.containStudent("S039489");
//    EXPECT_EQ(true, exit);
//    EXPECT_EQ(false, notexit);
//}
//
//// 没有学生时确实抛出异常
//TEST(GetAllStudents, NoStudentsExits){
//    std::string error;
//    InMemoryStudentRepository r;
//    try{
//        r.getAllStudents();
//    }
//    catch(StudentRepositotyError& e){
//        error = e.what();
//    }
//    EXPECT_EQ("No students in memory", error);
//}
//
////
//class InMemoryRepositoryStudentTest : public testing::Test {
//protected:
//    InMemoryRepositoryStudentTest(){
//        r.addStudent(Student{"S039482","James Smith",3});
//        r.addStudent(Student{"S712345","Jennifer Garcia",2});
//        r.addStudent(Student{"S198237","Robert Wilson",4});
//    }
//
//    InMemoryStudentRepository r;
//};
//
//TEST_F(InMemoryRepositoryStudentTest, GetStudentExit){
//    Student s = r.getStudent("S039482");
//
//    EXPECT_EQ("S039482", s.getStudentId());
//    EXPECT_EQ("James Smith", s.getFullName());
//    EXPECT_EQ(3, s.getLevel());
//}
//
//TEST_F(InMemoryRepositoryStudentTest, GetStudentNotExit){
//    std::string error;
//    try {
//        Student s = r.getStudent("S039486");
//    }
//    catch(StudentRepositotyError& e){
//        error = e.what();
//    }
//    EXPECT_EQ("Student with ID 'S039486' not found.", error);
//}
//
//// 剩下的使用差不多的方法写（ToDo...）
///******************* StudentInMemoryRepositoryTest**********************/
//
//
///******************* StudentFileRepositoryTest**********************/
////TEST(LoadData, FileNotExit){
////    std::string filepath = "../src/repositories/students.txt";
////    std::string error;
////
////    try {
////        FileStudentRepository fr(filepath);
////    }
////    catch (StudentRepositotyError& e){
////        error = e.what();
////    }
////    EXPECT_EQ("can not open: " + filepath + "!", error);
////}
//
//TEST(LoadData, FileExit){
//    std::string filepath = "../src/repositories/students.txt";
//    std::string error = "";
//
//    try {
//        FileStudentRepository fr(filepath);
//        EXPECT_EQ(true, fr.containStudent("S039482"));
//        EXPECT_EQ(true, fr.containStudent("S712345"));
//        EXPECT_EQ(true, fr.containStudent("S198237"));
//        EXPECT_EQ(true, fr.containStudent("S563289"));
//        EXPECT_EQ(true, fr.containStudent("S874563"));
//    }
//    catch (StudentRepositotyError& e){
//        error = e.what();
//    }
//    EXPECT_EQ("", error);
//}
//
//TEST(SaveData, AddNew){
//    std::string filepath = "../src/repositories/students.txt";
//
//    {
//        FileStudentRepository fr(filepath);
//        Student s1{"S753249","Elizabeth Jackson",2};
//        Student s2{"S864972","Joseph White",4};
//        fr.addStudent(s1);
//        fr.addStudent(s2);
//    }
//
//    FileStudentRepository fr1(filepath);
//    EXPECT_EQ(true, fr1.containStudent("S753249"));
//    EXPECT_EQ(true, fr1.containStudent("S864972"));
//}
//
//TEST(SaveData, DeleteAlreadyIn){
//    std::string filepath = "../src/repositories/students.txt";
//
//    {
//        FileStudentRepository fr(filepath);
//        fr.deleteStudent("S753249");
//        fr.deleteStudent("S864972");
//    }
//
//    FileStudentRepository fr1(filepath);
//    EXPECT_EQ(false, fr1.containStudent("S753249"));
//    EXPECT_EQ(false, fr1.containStudent("S864972"));
//}

/******************* CourseRepositoryTest**********************/
TEST(AddAndContainCourseTest, AddNotExit){
    InMemoryCourseRepository r;
    r.addCourse(Course{"C847502", "Introduction to Programming", "CS101",
                       "Fundamentals of programming using Python"});

    bool exit = r.containCourse("C847502");
    bool notexit = r.containCourse("C847505");
    EXPECT_EQ(true, exit);
    EXPECT_EQ(false, notexit);
}

// 没有学生时确实抛出异常
TEST(GetAllCourses, NoCoursesExits) {
    std::string error;
    InMemoryCourseRepository r;
    try {
        r.getAllCourses();
    }
    catch (CourseRepositotyError &e) {
        error = e.what();
    }
    EXPECT_EQ("No courses in memory", error);
}

class InMemoryRepositoryCourseTest : public testing::Test {
protected:
    InMemoryRepositoryCourseTest(){
        r.addCourse(Course{"C453627", "Web Development", "IT101",
                           "Building websites with HTML, CSS, and JavaScript"});
        r.addCourse(Course{"C789123", "Software Engineering", "SE201",
                           "Software development lifecycle and methodologies"});
        r.addCourse(Course{"C856123", "Human-Computer Interaction", "HCI101",
                           "UI/UX design principles"});
    }

    InMemoryCourseRepository r;
};

TEST_F(InMemoryRepositoryCourseTest, GetCourseExit){
    Course c = r.getCourse("C453627");

    EXPECT_EQ("C453627", c.getCourseId());
    EXPECT_EQ("Web Development", c.getCourseName());
    EXPECT_EQ("IT101", c.getCourseCode());
    EXPECT_EQ("Building websites with HTML, CSS, and JavaScript", c.getDescription());
}

TEST_F(InMemoryRepositoryCourseTest, GetCourseNotExit){
    std::string error;
    try {
        Course s = r.getCourse("C039486");
    }
    catch(CourseRepositotyError& e){
        error = e.what();
    }
    EXPECT_EQ("Course with ID 'C039486' not found.", error);
}

TEST(LoadData, CourseFileNotExit){
    std::string filepath = "../src/repositories/courses.txt";
    std::string error;

    try {
        FileCourseRepository fr(filepath);
    }
    catch (CourseRepositotyError& e){
        error = e.what();
    }
    EXPECT_EQ("can not open: " + filepath + "!", error);
}

TEST(LoadData, CourseFileExit){
    std::string filepath = "../src/repositories/courses.txt";
    std::string error;

    try {
        FileCourseRepository fr(filepath);
        EXPECT_EQ(true, fr.containCourse("C213654"));
        EXPECT_EQ(true, fr.containCourse("C635289"));
        EXPECT_EQ(true, fr.containCourse("C329476"));
        EXPECT_EQ(true, fr.containCourse("C453627"));
        EXPECT_EQ(true, fr.containCourse("C392615"));
    }
    catch (CourseRepositotyError& e){
        error = e.what();
    }
    EXPECT_EQ("", error);
}

TEST(CourseSaveData, AddNew){
    std::string filepath = "../src/repositories/courses.txt";

    {
        FileCourseRepository fr(filepath);
        Course s1{"C684275", "Parallel Computing", "CS701",
                  "Multithreading and distributed systems"};
        Course s2{"C375946", "Quantum Computing", "CS901",
                  "Introduction to quantum algorithms"};
        fr.addCourse(s1);
        fr.addCourse(s2);
    }

    FileCourseRepository fr1(filepath);
    EXPECT_EQ(true, fr1.containCourse("C684275"));
    EXPECT_EQ(true, fr1.containCourse("C375946"));
}

TEST(CourseSaveData, DeleteAlreadyIn){
    std::string filepath = "../src/repositories/courses.txt";

    {
        FileCourseRepository fr(filepath);
        fr.deleteCourse("C684275");
        fr.deleteCourse("C375946");
    }

    FileCourseRepository fr1(filepath);
    EXPECT_EQ(false, fr1.containCourse("C684275"));
    EXPECT_EQ(false, fr1.containCourse("C375946"));
}
/******************** CourseRepositoryTest**********************/