#include "CourseService.h"

CourseService::CourseService(std::shared_ptr<FileCourseRepository> fcr) : fcr(fcr) {}

void CourseService::addNewCourse(const Course& s) {
    fcr->addCourse(s);
}

Course CourseService::searchACourse(const std::string& sid) {
    return fcr->getCourse(sid);
}

void CourseService::updateACourse(const Course& s) {
    fcr->updateCourse(s);
}

void CourseService::deleteACourse(const std::string& sid) {
    fcr->deleteCourse(sid);
}

std::vector<Course> CourseService::searchAllCourses() {
    return fcr->getAllCourses();
}