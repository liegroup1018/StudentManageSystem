#ifndef CLIONVERSION_VALIDATION_H
#define CLIONVERSION_VALIDATION_H

#include <string>

class Validation {
public:
    // Student ID format: S followed by 6 digits (e.g., S123456)
    static bool isValidStudentId(const std::string& id);

    // Course ID format: C followed by 6 digits (e.g., C123456)
    static bool isValidCourseId(const std::string& id);

    // Grade format: an integer between 0 and 100 (inclusive)
    static bool isValidGrade(int grade);

    // Term format: YYYY-S#, where # is 1 or 2 (e.g., 2024-S1)
    static bool isValidTerm(const std::string& term);
};

#endif //CLIONVERSION_VALIDATION_H
