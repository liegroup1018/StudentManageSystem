//
// Created by oulashu on 2025/7/14.
//

#include "FileCourseRepository.h"

#include "FileCourseRepository.h"

Course FileCourseRepository::getCourse(const std::string &id) const {
    auto exist = [&id](const Course& s){
        return s.getCourseId() == id;
    };

    if(containCourse(id)){
        auto it = std::find_if(courses.begin(), courses.end(), exist);
        return *it;
    }
    throw CourseRepositotyError("Course with ID '" + id + "' not found.");
}

void FileCourseRepository::deleteCourse(const std::string &id) {
    if(containCourse(id)){
        auto exist = [&id](Course& s){
            return s.getCourseId() == id;
        };

        auto it = std::find_if(courses.begin(), courses.end(), exist);
        courses.erase(it);
        return;
    }
    throw CourseRepositotyError("Cannot delete. Course with ID '" + id + "' not found.");
}

void FileCourseRepository::updateCourse(const Course &course) {
    std::string id = course.getCourseId();
    if(containCourse(id)){
        auto exist = [&id](Course& s){
            return s.getCourseId() == id;
        };

        auto it = std::find_if(courses.begin(), courses.end(), exist);
        *it = course;
        return;
    }
    throw CourseRepositotyError("Cannot update. Course with ID '" + id + "' not found.");
}

std::vector<Course> FileCourseRepository::getAllCourses() const {
    if(!courses.empty()){
        return courses;
    }
    throw CourseRepositotyError("No Courses in file");
}

FileCourseRepository::FileCourseRepository(const std::string &filePath) : filePath(filePath) {
    loadData();
}

void FileCourseRepository::loadData() {
    std::ifstream f(filePath);

    if(!f){
        throw CourseRepositotyError("can not open: " + filePath + "!");
    }

    std::string id;
    std::string coursename;
    std::string coursecode;
    std::string description;

    // file open
    std::string buffer;
    std::getline(f, buffer); // 读取第一行, 是 field
    while (std::getline(f, buffer)){
        std::stringstream ss(buffer);

        std::getline(ss, id, ',');
        std::getline(ss, coursename, ',');
        std::getline(ss, coursecode, ',');
        std::getline(ss, description, ',');

        courses.emplace_back(id, coursename, coursecode, description);
    }

    f.close();
}

void FileCourseRepository::saveData() {
    // 以截断模式打开文件，从而清空文件中所有内容
    std::ofstream f(filePath, std::ios::trunc);

    f << "CourseId," << "CourseName," << "CourseCode," << "Description" << "\n";

    for(auto& s : courses){
        f << s.getCourseId() << ","
          << s.getCourseName() << ","
          << s.getCourseCode() << ","
          << s.getDescription() << "\n";
    }

    courses.clear();
    f.close();
}

FileCourseRepository::~FileCourseRepository() {
    saveData();
}


void FileCourseRepository::addCourse(const Course &Course) {
    std::string id = Course.getCourseId();
    if (!containCourse(id)){
        courses.push_back(Course);
        return;
    }

    throw CourseRepositotyError("Course with ID '" + id + "' already in.");
}

bool FileCourseRepository::containCourse(const std::string &id) const {
    // 注意常量 vector 的迭代器永远是常量迭代器并且解引用后也是常量引用
    // 所以 lambda 表达式的参数必须是常量引用
    auto exist = [&id](const Course& s){
        return s.getCourseId() == id;
    };

    auto it = std::find_if(courses.begin(), courses.end(), exist);
    if (it == courses.end())
        return false;
    else
        return true;
}
