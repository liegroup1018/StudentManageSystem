//
// Created by oulashu on 2025/7/11.
//
#include "gtest/gtest.h"
#include "IStudentRepository.h"
#include "FileStudentRepository.h"
#include "InMemoryStudentRepository.h"

/******************* StudentInMemoryRepositoryTest**********************/
/*
 * 系统中没有任何学生信息，添加新的学生信息
 */
TEST(AddAndContainStudentTest, AddNotExit){
    InMemoryStudentRepository r;
    r.addStudent(Student{"S039482","James Smith",3});

    bool exit = r.containStudent("S039482");
    bool notexit = r.containStudent("S039489");
    EXPECT_EQ(true, exit);
    EXPECT_EQ(false, notexit);
}

// 没有学生时确实抛出异常
TEST(GetAllStudents, NoStudentsExits){
    std::string error;
    InMemoryStudentRepository r;
    try{
        r.getAllStudents();
    }
    catch(StudentRepositotyError& e){
        error = e.what();
    }
    EXPECT_EQ("No students in memory", error);
}

//
class InMemoryRepositoryStudentTest : public testing::Test {
protected:
    InMemoryRepositoryStudentTest(){
        r.addStudent(Student{"S039482","James Smith",3});
        r.addStudent(Student{"S712345","Jennifer Garcia",2});
        r.addStudent(Student{"S198237","Robert Wilson",4});
    }

    InMemoryStudentRepository r;
};

TEST_F(InMemoryRepositoryStudentTest, GetStudentExit){
    Student s = r.getStudent("S039482");

    EXPECT_EQ("S039482", s.getStudentId());
    EXPECT_EQ("James Smith", s.getFullName());
    EXPECT_EQ(3, s.getLevel());
}

TEST_F(InMemoryRepositoryStudentTest, GetStudentNotExit){
    std::string error;
    try {
        Student s = r.getStudent("S039486");
    }
    catch(StudentRepositotyError& e){
        error = e.what();
    }
    EXPECT_EQ("Student with ID 'S039486' not found.", error);
}

// 剩下的使用差不多的方法写（ToDo...）
/******************* StudentInMemoryRepositoryTest**********************/


/******************* StudentFileRepositoryTest**********************/



/******************* StudentFileRepositoryTest**********************/