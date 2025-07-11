//
// Created by oulashu on 2025/7/9.
//

#ifndef CLIONVERSION_FILESTUDENTREPOSITORY_H
#define CLIONVERSION_FILESTUDENTREPOSITORY_H

#include "IStudentRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>

class FileStudentRepository : public IStudentRepository {
public:
    explicit FileStudentRepository(const std::string &filePath);

    void addStudent(const Student& student) override;

    Student getStudent(const std::string &id) const override;

    void deleteStudent(const std::string &id) override;

    void updateStudent(const Student &student) override;

    std::vector<Student> getAllStudents() const override;

    bool containStudent(const std::string& id) const override;

    virtual ~FileStudentRepository();

private:
    std::string filePath;
    std::vector<Student> students; // In-memory cache of the file data

    // Private helper methods to handle file I/O
    void loadData(); // Reads from the CSV file into the students vector
    void saveData(); // Writes the students vector back to the CSV file
};


#endif //CLIONVERSION_FILESTUDENTREPOSITORY_H
