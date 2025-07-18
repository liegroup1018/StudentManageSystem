//
// Created by oulashu on 2025/7/18.
//

#ifndef CLIONVERSION_STUDENTVIEW_H
#define CLIONVERSION_STUDENTVIEW_H

#include "BaseView.h"
#include <vector>
#include <string>
#include "../models/Student.h"

class StudentView : public BaseView {
public:
    // Display the student-specific submenu and returns the user's choice
    int showStudentMenu();

    // display a formatted list of all students
    void displayStudentList(const std::vector<Student>& students);

    // Displays the detailed information for a single student
    void displayStudentDetails(const Student& student);
};


#endif //CLIONVERSION_STUDENTVIEW_H
