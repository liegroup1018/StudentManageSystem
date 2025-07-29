#pragma once
#include "BaseView.h"
#include <vector>
#include <string>
#include "../models/Course.h"
#include <optional>

class CourseView : public BaseView
{
public:
    // --- Main Methods ---

   /*
   * Displays the course-specific submenu.
   * 1. Add a new course
   * 2. View a course details (accroding to id)
   * 3. Update a course details
   * 4. Delete a course
   * 5. list all courses
   */
    int showCourseMenu();

    // Displays a formatted list of all courses.
    void displayCourseList(const std::vector<Course>& courses);

    // Displays the detailed information for a course
    void displayCourseDetails(const Course& course);

    // Prompts for a course ID and validates its format. Allows cancellation.
    std::optional<std::string> getCourseIdInput();

    // Prompts for all data needed to create a new course. Allows cancellation.
    std::optional<Course> getNewCourseInfo();
};

