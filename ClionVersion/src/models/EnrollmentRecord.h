//
// Created by oulashu on 2025/7/8.
//

#ifndef CLIONVERSION_ENROLLMENTRECORD_H
#define CLIONVERSION_ENROLLMENTRECORD_H

#include <string>

class EnrollmentRecord {
public:
    EnrollmentRecord() = default;
    EnrollmentRecord(const std::string& sid, const std::string& cid, const std::string& term);

    std::string getStudentId() const;

    void setStudentId(const std::string &studentId);

    std::string getCourseId() const;

    void setCourseId(const std::string &courseId);

    std::string getTerm() const;

    void setTerm(const std::string &term);

    int getGrade() const;

    void setGrade(int grade);

    friend bool operator==(const EnrollmentRecord& lhs, const EnrollmentRecord& rhs);

private:
    std::string studentId;
    std::string courseId;
    std::string term;
    int grade = -1;
};


#endif //CLIONVERSION_ENROLLMENTRECORD_H
