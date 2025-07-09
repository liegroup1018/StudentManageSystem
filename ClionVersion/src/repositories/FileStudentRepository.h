//
// Created by oulashu on 2025/7/9.
//

#ifndef CLIONVERSION_FILESTUDENTREPOSITORY_H
#define CLIONVERSION_FILESTUDENTREPOSITORY_H

#include "IStudentRepository.h"

class FileStudentRepository : public IStudentRepository {
public:
    FileStudentRepository(const std::string &filePath);

    Student getStudent(const std::string &id) const override;

    void deleteStudent(const std::string &id) override;

    void updateStudent(const Student &student) override;

    std::vector<Student> getAllStudents() const override;

private:
    std::string filePath;
    std::vector<Student> students; // In-memory cache of the file data

    // Private helper methods to handle file I/O
    void loadData(); // Reads from the CSV file into the students vector
    void saveData(); // Writes the students vector back to the CSV file
};


#endif //CLIONVERSION_FILESTUDENTREPOSITORY_H
