cmake_minimum_required(VERSION 3.20)
project(ClionVersion)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(SIMS
                            src/models/Student.cpp
                            src/models/Student.h
                            src/models/Course.cpp
                            src/models/Course.h
                            src/models/EnrollmentRecord.cpp
                            src/models/EnrollmentRecord.h
                            src/repositories/IStudentRepository.h
                            src/repositories/InMemoryStudentRepository.cpp
                            src/repositories/InMemoryStudentRepository.h
                            src/repositories/FileStudentRepository.cpp
                            src/repositories/FileStudentRepository.h
                            src/repositories/RepositoriesUnitTest.cpp
                            src/repositories/ICourseRepository.h
                            src/repositories/InMemoryCourseRepository.cpp
                            src/repositories/InMemoryCourseRepository.h
                            src/repositories/FileCourseRepository.cpp
                            src/repositories/FileCourseRepository.h
                            src/repositories/IEnrollmentRepository.h
                            src/repositories/InMemoryEnrollmentRepository.cpp
                            src/repositories/InMemoryEnrollmentRepository.h
                            src/repositories/FileEnrollmentRepository.cpp
                            src/repositories/FileEnrollmentRepository.h)

enable_testing()
target_link_libraries(
        SIMS
        GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(SIMS)