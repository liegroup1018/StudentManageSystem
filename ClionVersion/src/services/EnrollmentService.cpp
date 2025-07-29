#include "EnrollmentService.h"

EnrollmentService::EnrollmentService(
        std::shared_ptr<FileEnrollmentRepository> fer,
        std::shared_ptr<FileStudentRepository> fsr,
        std::shared_ptr<FileCourseRepository> fcr):
        fer(fer), fsr(fsr), fcr(fcr){}

void EnrollmentService::enrollAStudent(const std::string& sid,
                                       const std::string& cid,
                                       const std::string& term) {
    EnrollmentRecord er(sid, cid, term);
    fer->addEnrollment(er);
}

void EnrollmentService::deleteAStudent(const std::string& sid, const std::string& cid) {
    fer->deleteEnrollment(sid, cid);
}

std::vector<Student> EnrollmentService::findAllStudentsForACourse(const std::string& cid) {
    std::vector<std::string> studentIds = fer->getAllStudentsForACourse(cid);
    std::vector<Student> students;
    for (const auto& sid : studentIds) {
        students.push_back(fsr->getStudent(sid));
    }
    return students;
}

std::vector<Course> EnrollmentService::findAllCoursesAStudentEnrolledIn(const std::string& sid) {
    std::vector<std::string> courseIds = fer->getAllCoursesForAStudent(sid);
    std::vector<Course> courses;
    for (const auto& cid : courseIds) {
        courses.push_back(fcr->getCourse(cid));
    }
    return courses;
}

void EnrollmentService::assignGradeForAStudent(const std::string& sid,
                                               const std::string& cid,
                                               int grade) {
    fer->assignGrade(sid, cid, grade);
}

std::vector<EnrollmentRecord> EnrollmentService::findGradesForAStudent(const std::string& sid) {
    std::vector<EnrollmentRecord> grades = fer->getGradesForAStudent(sid);
    return grades;
}

std::vector<EnrollmentRecord> EnrollmentService::findGradesForACourse(const std::string& cid) {
    std::vector<EnrollmentRecord> grades = fer->getGradesForACourse(cid);
    return grades;
}