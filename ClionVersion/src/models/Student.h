//
// Created by oulashu on 2025/7/8.
//

#ifndef CLIONVERSION_STUDENT_H
#define CLIONVERSION_STUDENT_H

#include <string>

class Student {
public:
    Student() = default;
    Student(const std::string& id, const std::string& name, int level );

    std::string getStudentId() const;

    void setStudentId(const std::string &studentId);

    std::string getFullName() const;

    void setFullName(const std::string &fullName);

    int getLevel() const;

    void setLevel(int level);

private:
    std::string studentId;
    std::string fullName;
    int level;
};


#endif //CLIONVERSION_STUDENT_H
