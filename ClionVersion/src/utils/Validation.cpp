#include "Validation.h"
#include <regex>

bool Validation::isValidStudentId(const std::string& id) {
    // Matches 'S' followed by exactly 6 digits.
    return std::regex_match(id, std::regex("S\\d{6}"));
}

bool Validation::isValidCourseId(const std::string& id) {
    // Matches 'C' followed by exactly 6 digits.
    return std::regex_match(id, std::regex("C\\d{6}"));
}

bool Validation::isValidGrade(int grade) {
    // Checks if the grade is within the valid range.
    return grade >= 0 && grade <= 100;
}

bool Validation::isValidTerm(const std::string& term) {
    // Matches a four-digit year, followed by '-S', and then either '1' or '2'.
    // Example: "2024-S1"
    return std::regex_match(term, std::regex("\\d{4}-S[1-2]"));
}

