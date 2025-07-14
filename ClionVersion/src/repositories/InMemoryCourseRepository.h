//
// Created by oulashu on 2025/7/14.
//

#ifndef CLIONVERSION_INMEMORYCOURSEREPOSITORY_H
#define CLIONVERSION_INMEMORYCOURSEREPOSITORY_H


#include "ICourseRepository.h"
#include <algorithm> // For std::find_if
#include <unordered_map>

class InMemoryCourseRepository : public ICourseRepository{
public:
    InMemoryCourseRepository() = default;

    void addCourse(const Course& Course) override;

    Course getCourse(const std::string &id) const override;

    void deleteCourse(const std::string &id) override;

    void updateCourse(const Course &Course) override;

    bool containCourse(const std::string& id) const override;

    std::vector<Course> getAllCourses() const override;

private:
    std::unordered_map<std::string, Course> courses;
};


#endif //CLIONVERSION_INMEMORYCOURSEREPOSITORY_H
