//
// Created by oulashu on 2025/7/18.
//

#ifndef CLIONVERSION_STUDENTVIEW_H
#define CLIONVERSION_STUDENTVIEW_H

#include "BaseView.h"
#include <vector>
#include <string>
#include "../models/Student.h"
#include <optional>

class StudentView : public BaseView {
public:

    /* Display the student-specific submenu and returns the user's choice
    *  1. Add a new student
    *  2. View a student details (accroding to id)
    *  3. Update a student details
    *  4. Delete a student
    *  5. list all students
    */
    int showStudentMenu();

    // display a formatted list of all students
    void displayStudentList(const std::vector<Student>& students);

    // Displays the detailed information for a single student
    void displayStudentDetails(const Student& student);

    // Prompts the user for a student ID and validates its format. Allows cancellation.
    std::optional<std::string> getStudentIdInput();

    // Prompts for all data needed to create a new student. Allows cancellation.
    std::optional<Student> getNewStudentInfo();
};


#endif //CLIONVERSION_STUDENTVIEW_H
