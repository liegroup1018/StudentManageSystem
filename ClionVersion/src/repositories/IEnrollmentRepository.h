//
// Created by oulashu on 2025/7/14.
//

#ifndef CLIONVERSION_IENROLLMENTREPOSITORY_H
#define CLIONVERSION_IENROLLMENTREPOSITORY_H
#include "../models/EnrollmentRecord.h"
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <unordered_map>


class EnollmentRepositotyError : public std::runtime_error {
public:
    EnollmentRepositotyError(const std::string& s) : std::runtime_error(s){}
};

class IEnollmentRepository{
public:
    virtual ~IEnollmentRepository() = default;

    // --- Required Methods (The Contract) ---

    // 保存一条新的登记信息
    virtual void addEnrollment(const EnrollmentRecord& e) = 0;

    // 删除一条登记信息
    virtual void deleteEnrollment(const std::string& sid, const std::string& cid) = 0;

    // 读取选择指定课程的所有学生
    virtual std::vector<std::string> getAllStudentsForACourse(const std::string& cid) = 0;

    // 读取指定学生选择的所有课程
    virtual std::vector<std::string> getAllCoursesForAStudent(const std::string& sid) = 0;

    // 获取某个学生某门课的成绩
    virtual int getGrade(const std::string& sid, const std::string& cid) = 0;

    // 读取指定学生所有课程的成绩,key:courseID, value: grade
    virtual std::vector<EnrollmentRecord>
    getGradesForAStudent(const std::string& sid) = 0;

    // 读取指定课程所有学生的成绩
    virtual std::vector<EnrollmentRecord>
    getGradesForACourse(const std::string& cid) = 0;

    // 保存某个学生某门课的成绩
    virtual void assignGrade(const std::string& sid, const std::string& cid, int grade) = 0;

    virtual bool containsEnrollment(const std::string& sid, const std::string& cid) = 0;

};
#endif //CLIONVERSION_IENROLLMENTREPOSITORY_H
