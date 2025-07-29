#include "gtest/gtest.h"
#include "Validation.h"

// --- Test Fixture for Validation ---
// A test fixture can be used to set up objects or state needed by all tests in a test suite.
class ValidationTest : public ::testing::Test {
protected:
    // This method is called before each test.
    void SetUp() override {
        // No setup needed for these static validation methods.
    }

    // This method is called after each test.
    void TearDown() override {
        // No cleanup needed.
    }
};

// --- Tests for isValidStudentId ---

// Test case for valid student IDs
TEST_F(ValidationTest, IsValidStudentId_CorrectFormat) {
    EXPECT_TRUE(Validation::isValidStudentId("S123456"));
    EXPECT_TRUE(Validation::isValidStudentId("S000000"));
    EXPECT_TRUE(Validation::isValidStudentId("S999999"));
}

// Test case for invalid student IDs
TEST_F(ValidationTest, IsValidStudentId_IncorrectFormat) {
    EXPECT_FALSE(Validation::isValidStudentId("s123456")); // Lowercase 's'
    EXPECT_FALSE(Validation::isValidStudentId("S12345"));  // Too few digits
    EXPECT_FALSE(Validation::isValidStudentId("S1234567")); // Too many digits
    EXPECT_FALSE(Validation::isValidStudentId("C123456"));  // Wrong starting letter
    EXPECT_FALSE(Validation::isValidStudentId("S12345A")); // Contains non-digit
    EXPECT_FALSE(Validation::isValidStudentId("S 123456"));// Contains space
    EXPECT_FALSE(Validation::isValidStudentId(""));         // Empty string
    EXPECT_FALSE(Validation::isValidStudentId("S-12345")); // Contains special character
}

// --- Tests for isValidCourseId ---

// Test case for valid course IDs
TEST_F(ValidationTest, IsValidCourseId_CorrectFormat) {
    EXPECT_TRUE(Validation::isValidCourseId("C123456"));
    EXPECT_TRUE(Validation::isValidCourseId("C000000"));
    EXPECT_TRUE(Validation::isValidCourseId("C999999"));
}

// Test case for invalid course IDs
TEST_F(ValidationTest, IsValidCourseId_IncorrectFormat) {
    EXPECT_FALSE(Validation::isValidCourseId("c123456")); // Lowercase 'c'
    EXPECT_FALSE(Validation::isValidCourseId("C12345"));  // Too few digits
    EXPECT_FALSE(Validation::isValidCourseId("C1234567")); // Too many digits
    EXPECT_FALSE(Validation::isValidCourseId("S123456"));  // Wrong starting letter
    EXPECT_FALSE(Validation::isValidCourseId("C12345A")); // Contains non-digit
    EXPECT_FALSE(Validation::isValidCourseId("C 123456"));// Contains space
    EXPECT_FALSE(Validation::isValidCourseId(""));         // Empty string
    EXPECT_FALSE(Validation::isValidCourseId("C-12345")); // Contains special character
}

// --- Tests for isValidGrade ---

// Test case for valid grades
TEST_F(ValidationTest, IsValidGrade_CorrectRange) {
    EXPECT_TRUE(Validation::isValidGrade(0));    // Lower boundary
    EXPECT_TRUE(Validation::isValidGrade(50));   // Middle of the range
    EXPECT_TRUE(Validation::isValidGrade(100));  // Upper boundary
}

// Test case for invalid grades (out of range)
TEST_F(ValidationTest, IsValidGrade_IncorrectRange) {
    EXPECT_FALSE(Validation::isValidGrade(-1));  // Below lower boundary
    EXPECT_FALSE(Validation::isValidGrade(101)); // Above upper boundary
}

// --- Tests for isValidTerm ---

// Test case for valid term formats
TEST_F(ValidationTest, IsValidTerm_CorrectFormat) {
    EXPECT_TRUE(Validation::isValidTerm("2024-S1"));
    EXPECT_TRUE(Validation::isValidTerm("2025-S2"));
    EXPECT_TRUE(Validation::isValidTerm("1999-S1"));
}

// Test case for invalid term formats
TEST_F(ValidationTest, IsValidTerm_IncorrectFormat) {
    EXPECT_FALSE(Validation::isValidTerm("2024-s1")); // Lowercase 's'
    EXPECT_FALSE(Validation::isValidTerm("2024-S3")); // Invalid semester number
    EXPECT_FALSE(Validation::isValidTerm("202-S1"));  // Not enough digits in year
    EXPECT_FALSE(Validation::isValidTerm("2024S1"));  // Missing hyphen
    EXPECT_FALSE(Validation::isValidTerm("2024-S 1"));// Contains space
    EXPECT_FALSE(Validation::isValidTerm(""));        // Empty string
    EXPECT_FALSE(Validation::isValidTerm("2024-S0")); // Invalid semester number (zero)
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}