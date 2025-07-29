//
// Created by oulashu on 2025/7/14.
//

#ifndef CLIONVERSION_ICOURSEREPOSITORY_H
#define CLIONVERSION_ICOURSEREPOSITORY_H
#include "../models/Course.h"
#include <vector>
#include <stdexcept> // For std::runtime_error

class CourseRepositotyError : public std::runtime_error {
public:
    CourseRepositotyError(const std::string& s) : std::runtime_error(s){}
};


// The "Interface" for all Course repositories.
// It defines the contract of what a repository can do, but not how it does it.
class ICourseRepository {
public:
    // A virtual destructor is essential for any class intended for polymorphic use.
    virtual ~ICourseRepository() = default;

    // --- Required Methods (The Contract) ---

    // add a new Course to the container
    virtual void addCourse(const Course& Course) = 0;
    // Retrieves a single Course by their ID.
    // Throws std::runtime_error if the Course is not found.
    virtual Course getCourse(const std::string& id) const = 0;

    // Removes a Course from the data source by their ID.
    // Throws std::runtime_error if the Course is not found.
    virtual void deleteCourse(const std::string& id) = 0;

    // Modifies an existing Course's data. Finds the Course by Course.CourseId.
    // Throws std::runtime_error if the Course to update is not found.
    virtual void updateCourse(const Course& Course) = 0;

    // 检查是否存在指定学生，存在则返回 true, 不存在则返回 false
    virtual bool containCourse(const std::string& id) const = 0;

    // Retrieves a collection of all Courses.
    // Throws std::runtime_error if no Course exists
    virtual std::vector<Course> getAllCourses() const = 0;

};
#endif //CLIONVERSION_ICOURSEREPOSITORY_H

