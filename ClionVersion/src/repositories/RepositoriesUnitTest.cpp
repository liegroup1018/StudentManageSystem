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
#include "IEnrollmentRepository.h"
#include "InMemoryEnrollmentRepository.h"
#include "FileEnrollmentRepository.h"

/******************* StudentInMemoryRepositoryTest**********************/
///*
// * ϵͳ��û���κ�ѧ����Ϣ������µ�ѧ����Ϣ
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
//// û��ѧ��ʱȷʵ�׳��쳣
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
//// ʣ�µ�ʹ�ò��ķ���д��ToDo...��
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
//TEST(AddAndContainCourseTest, AddNotExit){
//    InMemoryCourseRepository r;
//    r.addCourse(Course{"C847502", "Introduction to Programming", "CS101",
//                       "Fundamentals of programming using Python"});
//
//    bool exit = r.containCourse("C847502");
//    bool notexit = r.containCourse("C847505");
//    EXPECT_EQ(true, exit);
//    EXPECT_EQ(false, notexit);
//}
//
//// û��ѧ��ʱȷʵ�׳��쳣
//TEST(GetAllCourses, NoCoursesExits) {
//    std::string error;
//    InMemoryCourseRepository r;
//    try {
//        r.getAllCourses();
//    }
//    catch (CourseRepositotyError &e) {
//        error = e.what();
//    }
//    EXPECT_EQ("No courses in memory", error);
//}
//
//class InMemoryRepositoryCourseTest : public testing::Test {
//protected:
//    InMemoryRepositoryCourseTest(){
//        r.addCourse(Course{"C453627", "Web Development", "IT101",
//                           "Building websites with HTML, CSS, and JavaScript"});
//        r.addCourse(Course{"C789123", "Software Engineering", "SE201",
//                           "Software development lifecycle and methodologies"});
//        r.addCourse(Course{"C856123", "Human-Computer Interaction", "HCI101",
//                           "UI/UX design principles"});
//    }
//
//    InMemoryCourseRepository r;
//};
//
//TEST_F(InMemoryRepositoryCourseTest, GetCourseExit){
//    Course c = r.getCourse("C453627");
//
//    EXPECT_EQ("C453627", c.getCourseId());
//    EXPECT_EQ("Web Development", c.getCourseName());
//    EXPECT_EQ("IT101", c.getCourseCode());
//    EXPECT_EQ("Building websites with HTML, CSS, and JavaScript", c.getDescription());
//}
//
//TEST_F(InMemoryRepositoryCourseTest, GetCourseNotExit){
//    std::string error;
//    try {
//        Course s = r.getCourse("C039486");
//    }
//    catch(CourseRepositotyError& e){
//        error = e.what();
//    }
//    EXPECT_EQ("Course with ID 'C039486' not found.", error);
//}
//
//TEST(LoadData, CourseFileNotExit){
//    std::string filepath = "../src/repositories/courses.txt";
//    std::string error;
//
//    try {
//        FileCourseRepository fr(filepath);
//    }
//    catch (CourseRepositotyError& e){
//        error = e.what();
//    }
//    EXPECT_EQ("can not open: " + filepath + "!", error);
//}
//
//TEST(LoadData, CourseFileExit){
//    std::string filepath = "../src/repositories/courses.txt";
//    std::string error;
//
//    try {
//        FileCourseRepository fr(filepath);
//        EXPECT_EQ(true, fr.containCourse("C213654"));
//        EXPECT_EQ(true, fr.containCourse("C635289"));
//        EXPECT_EQ(true, fr.containCourse("C329476"));
//        EXPECT_EQ(true, fr.containCourse("C453627"));
//        EXPECT_EQ(true, fr.containCourse("C392615"));
//    }
//    catch (CourseRepositotyError& e){
//        error = e.what();
//    }
//    EXPECT_EQ("", error);
//}
//
//TEST(CourseSaveData, AddNew){
//    std::string filepath = "../src/repositories/courses.txt";
//
//    {
//        FileCourseRepository fr(filepath);
//        Course s1{"C684275", "Parallel Computing", "CS701",
//                  "Multithreading and distributed systems"};
//        Course s2{"C375946", "Quantum Computing", "CS901",
//                  "Introduction to quantum algorithms"};
//        fr.addCourse(s1);
//        fr.addCourse(s2);
//    }
//
//    FileCourseRepository fr1(filepath);
//    EXPECT_EQ(true, fr1.containCourse("C684275"));
//    EXPECT_EQ(true, fr1.containCourse("C375946"));
//}
//
//TEST(CourseSaveData, DeleteAlreadyIn){
//    std::string filepath = "../src/repositories/courses.txt";
//
//    {
//        FileCourseRepository fr(filepath);
//        fr.deleteCourse("C684275");
//        fr.deleteCourse("C375946");
//    }
//
//    FileCourseRepository fr1(filepath);
//    EXPECT_EQ(false, fr1.containCourse("C684275"));
//    EXPECT_EQ(false, fr1.containCourse("C375946"));
//}
/******************** CourseRepositoryTest**********************/


/******************** EnrollmentsRepositoryTest**********************/
TEST(AddAndContainEnrollmentTest, AddNotExit){
    InMemoryEnrollmentRepository r;
    r.addEnrollment(EnrollmentRecord{"S039482", "C213654", "Fall 2023"});

    bool exit = r.containsEnrollment("S039482", "C213654");
    bool notexit = r.containsEnrollment("S039488", "C213654");
    EXPECT_EQ(true, exit);
    EXPECT_EQ(false, notexit);
}

//class InMemoryRepositoryEnrollmentTest : public testing::Test {
//protected:
//    InMemoryRepositoryEnrollmentTest(){
//        r.addEnrollment(EnrollmentRecord{"S039482", "C213654", "Fall 2023"});
//        r.addEnrollment(EnrollmentRecord{"S712345", "C635289", "Spring 2024"});
//        r.addEnrollment(EnrollmentRecord{"S198237", "C329476", "Winter 2023"});
//        r.assignGrade("S712345", "C635289",78);
//        r.assignGrade("S198237", "C329476",92);
//    }
//
//    InMemoryEnrollmentRepository r;
//};
//
//TEST_F(InMemoryRepositoryEnrollmentTest, DeleteExit){
//    std::string error;
//    try {
//        EnrollmentRecord en{"S039482", "C213654", "Fall 2023"};
//        r.deleteEnrollment(en);
//    }
//    catch(EnollmentRepositotyError& e) {
//        error = e.what();
//    }
//    EXPECT_EQ(error, "");
//}
//
//TEST_F(InMemoryRepositoryEnrollmentTest, DeleteNotExit){
//    std::string error;
//    try {
//        EnrollmentRecord en{"S039481", "C213653", "Fall 2023"};
//        r.deleteEnrollment(en);
//    }
//    catch(EnollmentRepositotyError& e) {
//        error = e.what();
//    }
//    EXPECT_EQ(error, "Can not delete! Enrollment with Student ID "
//                     "'S039481' and Course ID 'C213653' not found.");
//}
//
//TEST_F(InMemoryRepositoryEnrollmentTest, AssignGrade){
//    int grade;
//    try{
//        r.assignGrade("S039482", "C213654",98);
//        grade = r.getGrade("S039482", "C213654");
//    }
//    catch(EnollmentRepositotyError& e) {
//
//    }
//    EXPECT_EQ(98, grade);
//}
//
//TEST_F(InMemoryRepositoryEnrollmentTest, AllStudentsForACourse){
//    std::vector<std::string> st;
//    try{
//        st = r.getAllStudentsForACourse("C213654");
//    }
//    catch(EnollmentRepositotyError& e){
//
//    }
//    auto begin = st.begin();
//    auto end = st.end();
//
//    EXPECT_GT(std::count(begin,end,"S039482"),0);
//}
//
//TEST_F(InMemoryRepositoryEnrollmentTest, AllCoursesForAStudent){
//    std::vector<std::string> cr;
//    try{
//        cr = r.getAllCoursesForAStudent("S039482");
//    }
//    catch(EnollmentRepositotyError& e){
//
//    }
//    auto begin = cr.begin();
//    auto end = cr.end();
//
//    EXPECT_GT(std::count(begin,end,"C213654"),0);
//}
//
//TEST_F(InMemoryRepositoryEnrollmentTest, GradesForAStudent){
//    std::unordered_map<std::string, int> s;
//    try{
//        s = r.getGradesForAStudent("S712345");
//    }catch(EnollmentRepositotyError& e){
//
//    }
//
//    EXPECT_GT(s.count("C635289"),0);
//    EXPECT_EQ(s["C635289"], 78);
//}
//
//TEST_F(InMemoryRepositoryEnrollmentTest, GradesForACourse){
//    std::unordered_map<std::string, int> c;
//    try{
//        c = r.getGradesForACourse("C329476");
//    }catch(EnollmentRepositotyError& e){
//
//    }
//
//    EXPECT_GT(c.count("S198237"),0);
//    EXPECT_EQ(c["S198237"], 92);
//}

//TEST(LoadData, EnrollmentFileNotExit){
//    std::string filepath = "../src/repositories/enrollmentrecors.txt";
//    std::string error;
//
//
//    try {
//        FileEnrollmentRepository fr(filepath);
//    }
//    catch (EnollmentRepositotyError& e){
//        error = e.what();
//    }
//    EXPECT_EQ("can not open: " + filepath + "!", error);
//}

TEST(LoadData, EnrollmentFileExit){
    std::string filepath = "src/repositories/enrollmentrecors.txt";
    std::string error;

    try {
        FileEnrollmentRepository fr(filepath);
        EXPECT_EQ(true, fr.containsEnrollment("S039482", "C213654"));
        EXPECT_EQ(true, fr.containsEnrollment("S712345", "C635289"));
        EXPECT_EQ(true, fr.containsEnrollment("S198237", "C329476"));
        EXPECT_EQ(true, fr.containsEnrollment("S563289", "C453627"));
        EXPECT_EQ(true, fr.containsEnrollment("S874563", "C392615"));
    }
    catch (CourseRepositotyError& e){
        error = e.what();
    }
    EXPECT_EQ("", error);
}
//
//TEST(EnrollmentSaveData, AddNew){
//    std::string filepath = "src/repositories/enrollmentrecors.txt";
//
//    {
//        FileEnrollmentRepository fr(filepath);
//        EnrollmentRecord e1{"S039482", "C635289", "Spring 2024"};
//        e1.setGrade(81);
//        EnrollmentRecord e2{"S712345", "C213654", "Fall 2023"};
//        e2.setGrade(90);
//        fr.addEnrollment(e1);
//        fr.addEnrollment(e2);
//    }
//
//    FileEnrollmentRepository fr1(filepath);
//    EXPECT_EQ(true, fr1.containsEnrollment("S039482", "C635289"));
//    EXPECT_EQ(true, fr1.containsEnrollment("S712345", "C213654"));
//}

//TEST(EnrollmentSaveData, DeleteAlreadyIn){
//    std::string filepath = "src/repositories/enrollmentrecors.txt";
//
//    {
//        FileEnrollmentRepository fr(filepath);
//        EnrollmentRecord e1{"S039482", "C635289", "Spring 2024"};
//        EnrollmentRecord e2{"S712345", "C213654", "Fall 2023"};
//        fr.deleteEnrollment(e1);
//        fr.deleteEnrollment(e2);
//    }
//
//    FileEnrollmentRepository fr1(filepath);
//    EXPECT_EQ(false, fr1.containsEnrollment("S039482", "C635289"));
//    EXPECT_EQ(false, fr1.containsEnrollment("S712345", "C213654"));
//}
/******************** EnrollmentsRepositoryTest**********************/

//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}