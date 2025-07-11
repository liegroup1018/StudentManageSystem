//
// Created by oulashu on 2025/7/9.
//

#include "FileStudentRepository.h"

Student FileStudentRepository::getStudent(const std::string &id) const {
    auto exist = [&id](const Student& s){
        return s.getStudentId() == id;
    };

    if(containStudent(id)){
        auto it = std::find_if(students.begin(), students.end(), exist);
        return *it;
    }
    throw StudentRepositotyError("Student with ID '" + id + "' not found.");
}

void FileStudentRepository::deleteStudent(const std::string &id) {
    if(containStudent(id)){
        auto exist = [&id](Student& s){
            return s.getStudentId() == id;
        };

        auto it = std::find_if(students.begin(), students.end(), exist);
        students.erase(it);
    }
    throw StudentRepositotyError("Cannot delete. Student with ID '" + id + "' not found.");
}

void FileStudentRepository::updateStudent(const Student &student) {
    std::string id = student.getStudentId();
    if(containStudent(id)){
        auto exist = [&id](Student& s){
            return s.getStudentId() == id;
        };

        auto it = std::find_if(students.begin(), students.end(), exist);
        *it = student;
    }
    throw StudentRepositotyError("Cannot update. Student with ID '" + id + "' not found.");
}

std::vector<Student> FileStudentRepository::getAllStudents() const {
    if(!students.empty()){
        return students;
    }
    throw StudentRepositotyError("No students in file");
}

FileStudentRepository::FileStudentRepository(const std::string &filePath) : filePath(filePath) {
    loadData();
}

void FileStudentRepository::loadData() {
    std::ifstream f(filePath);

    if(!f){
        throw StudentRepositotyError("can not open: " + filePath + "!");
    }

    std::string id;
    std::string name;
    std::string levelStr;

    // file open
    std::string buffer;
    std::getline(f, buffer); // 读取第一行, 是 field
    while (std::getline(f, buffer)){
        std::stringstream ss(buffer);

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, levelStr, ',');

        students.emplace_back(id, name, std::stoi(levelStr));
    }

    f.close();
}

void FileStudentRepository::saveData() {
    // 以截断模式打开文件，从而清空文件中所有内容
    std::ofstream f(filePath, std::ios::trunc);

    f << "StudentId," << "FullName," << "Level" <<"\n";

    for(auto& s : students){
        f << s.getStudentId() << ","
          << s.getFullName() << ","
          << s.getLevel() << "\n";
    }

    students.clear();
    f.close();
}

FileStudentRepository::~FileStudentRepository() {
    saveData();
}


void FileStudentRepository::addStudent(const Student &student) {
    students.push_back(student);
}

bool FileStudentRepository::containStudent(const std::string &id) const {
    // 注意常量 vector 的迭代器永远是常量迭代器并且解引用后也是常量引用
    // 所以 lambda 表达式的参数必须是常量引用
    auto exist = [&id](const Student& s){
        return s.getStudentId() == id;
    };

    auto it = std::find_if(students.begin(), students.end(), exist);
    if (it == students.end())
        return false;
    else
        return true;
}
