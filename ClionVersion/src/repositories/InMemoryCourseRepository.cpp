//
// Created by oulashu on 2025/7/14.
//

#include "InMemoryCourseRepository.h"

#include "InMemoryCourseRepository.h"

Course InMemoryCourseRepository::getCourse(const std::string &id) const {
    auto it = courses.find(id);
    if ( it != courses.end()){
        return it->second;
    }

    throw CourseRepositotyError("Course with ID '" + id + "' not found.");
}

void InMemoryCourseRepository::deleteCourse(const std::string &id) {
    auto it = courses.find(id);
    if ( it != courses.end()){
        courses.erase(it);
    }

    throw CourseRepositotyError("Cannot delete. Course with ID '" + id + "' not found.");
}

void InMemoryCourseRepository::updateCourse(const Course &Course) {
    std::string id = Course.getCourseId();
    auto it = courses.find(id);
    if ( it != courses.end()){
        courses[id] = Course;
    }

    throw CourseRepositotyError("Cannot update. Course with ID '" + id + "' not found.");
}

std::vector<Course> InMemoryCourseRepository::getAllCourses() const {
    std::vector<Course> s;
    if (!courses.empty()){
        for(auto &it : courses){
            s.push_back(it.second);
        }
        return std::move(s);
    }

    throw CourseRepositotyError("No courses in memory");
}

void InMemoryCourseRepository::addCourse(const Course &Course) {
    std::string id = Course.getCourseId();
    if(!containCourse(id)){
        courses[Course.getCourseId()] = Course;
        return;
    }

    throw CourseRepositotyError("Course with ID '" + id + "' already in.");
}

bool InMemoryCourseRepository::containCourse(const std::string &id) const {
    if (courses.find(id) == courses.end()){
        return false;
    }
    return true;
}