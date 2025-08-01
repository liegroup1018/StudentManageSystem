//
// Created by oulashu on 2025/7/14.
//

#ifndef CLIONVERSION_INMEMORYENROLLMENTREPOSITORY_H
#define CLIONVERSION_INMEMORYENROLLMENTREPOSITORY_H
#include "IEnrollmentRepository.h"
#include <algorithm>

class InMemoryEnrollmentRepository : public IEnollmentRepository{
public:
    InMemoryEnrollmentRepository() = default;

    ~InMemoryEnrollmentRepository() override = default;

    void addEnrollment(const EnrollmentRecord &e) override;

    void deleteEnrollment(const std::string& sid, const std::string& cid) override;

    std::vector<std::string> getAllStudentsForACourse(const std::string &cid) override;

    std::vector<std::string> getAllCoursesForAStudent(const std::string &sid) override;

    int getGrade(const std::string &sid, const std::string &cid) override;

    std::vector<EnrollmentRecord> getGradesForAStudent(const std::string &sid) override;

    std::vector<EnrollmentRecord> getGradesForACourse(const std::string &cid) override;

    bool containsEnrollment(const std::string &sid, const std::string &cid) override;

    void assignGrade(const std::string &sid, const std::string &cid, int grade) override;

private:
    std::vector<EnrollmentRecord> enrollments;
};


#endif //CLIONVERSION_INMEMORYENROLLMENTREPOSITORY_H
