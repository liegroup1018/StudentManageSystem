#include "StudentService.h"

StudentService::StudentService(std::shared_ptr<FileStudentRepository> fsr) : fsr(fsr) {}

void StudentService::addNewStudent(const Student& s) {
    fsr->addStudent(s);
}

Student StudentService::searchAStudent(const std::string& sid) {
    return fsr->getStudent(sid);
}

void StudentService::updateAStudent(const Student& s) {
    fsr->updateStudent(s);
}

void StudentService::deleteAStudent(const std::string& sid) {
    fsr->deleteStudent(sid);
}

std::vector<Student> StudentService::searchAllStudents() {
    return fsr->getAllStudents();
}