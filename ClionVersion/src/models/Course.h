//
// Created by oulashu on 2025/7/8.
//

#ifndef CLIONVERSION_COURSE_H
#define CLIONVERSION_COURSE_H

#include <string>

class Course {
public:
    Course() = default;
    Course(const std::string& id, const std::string& name,
           const std::string& code, const std::string& des);

    std::string getCourseId() const;

    void setCourseId(const std::string &courseId);

    std::string getCourseName() const;

    void setCourseName(const std::string &courseName);

    std::string getCourseCode() const;

    void setCourseCode(const std::string &courseCode);

    std::string getDescription() const;

    void setDescription(const std::string &description);

private:
    std::string courseId;
    std::string courseName;
    std::string courseCode;
    std::string description;
};


#endif //CLIONVERSION_COURSE_H
