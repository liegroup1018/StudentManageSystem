//
// Created by oulashu on 2025/7/14.
//

#ifndef CLIONVERSION_FILECOURSEREPOSITORY_H
#define CLIONVERSION_FILECOURSEREPOSITORY_H

#include "ICourseRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>

class FileCourseRepository : public ICourseRepository {
public:
    explicit FileCourseRepository(const std::string &filePath);

    void addCourse(const Course& Course) override;

    Course getCourse(const std::string &id) const override;

    void deleteCourse(const std::string &id) override;

    void updateCourse(const Course &Course) override;

    std::vector<Course> getAllCourses() const override;

    bool containCourse(const std::string& id) const override;

    virtual ~FileCourseRepository();

private:
    std::string filePath;
    std::vector<Course> courses; // In-memory cache of the file data

    // Private helper methods to handle file I/O
    void loadData(); // Reads from the CSV file into the Courses vector
    void saveData(); // Writes the Courses vector back to the CSV file
};


#endif //CLIONVERSION_FILECOURSEREPOSITORY_H
