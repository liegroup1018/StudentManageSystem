//
// Created by oulashu on 2025/7/17.
//

#ifndef CLIONVERSION_FILEENROLLMENTREPOSITORY_H
#define CLIONVERSION_FILEENROLLMENTREPOSITORY_H

#include "IEnrollmentRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>

class FileEnrollmentRepository : public IEnollmentRepository{
public:
    explicit FileEnrollmentRepository(std::string filepath);

    ~FileEnrollmentRepository() override;

    void addEnrollment(const EnrollmentRecord &e) override;

    void deleteEnrollment(const std::string& sid, const std::string& cid) override;

    std::vector<std::string> getAllStudentsForACourse(const std::string &cid) override;

    std::vector<std::string> getAllCoursesForAStudent(const std::string &sid) override;

    int getGrade(const std::string &sid, const std::string &cid) override;

    std::vector<EnrollmentRecord> getGradesForAStudent(const std::string &sid) override;

    std::vector<EnrollmentRecord> getGradesForACourse(const std::string &cid) override;

    void assignGrade(const std::string &sid, const std::string &cid, int grade) override;

    bool containsEnrollment(const std::string &sid, const std::string &cid) override;

private:
    std::string filePath;
    std::vector<EnrollmentRecord> enrollments; // In-memory cache of the file data

    // Private helper methods to handle file I/O
    void loadData(); // Reads from the CSV file into the enrollments vector
    void saveData(); // Writes the enrollments vector back to the CSV file
};


#endif //CLIONVERSION_FILEENROLLMENTREPOSITORY_H
