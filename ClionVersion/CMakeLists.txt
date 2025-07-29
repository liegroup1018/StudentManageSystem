cmake_minimum_required(VERSION 3.20)
project(ClionVersion)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
#find_package(GMock REQUIRED)

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
                            #src/repositories/RepositoriesUnitTest.cpp
                            src/repositories/ICourseRepository.h
                            src/repositories/InMemoryCourseRepository.cpp
                            src/repositories/InMemoryCourseRepository.h
                            src/repositories/FileCourseRepository.cpp
                            src/repositories/FileCourseRepository.h
                            src/repositories/IEnrollmentRepository.h
                            src/repositories/InMemoryEnrollmentRepository.cpp
                            src/repositories/InMemoryEnrollmentRepository.h
                            src/repositories/FileEnrollmentRepository.cpp
                            src/repositories/FileEnrollmentRepository.h
                            src/views/BaseView.cpp
                            src/views/BaseView.h
                            src/views/MainView.cpp
                            src/views/MainView.h
                            src/views/StudentView.cpp
                            src/views/StudentView.h
                            src/views/CourseView.h
                            src/views/CourseView.cpp
                            src/views/EnrollmentView.cpp
                            src/views/EnrollmentView.h
                            src/services/CourseService.cpp
                            src/services/CourseService.h
                            src/services/EnrollmentService.cpp
                            src/services/EnrollmentService.h
                            src/services/StudentService.cpp
                            src/services/StudentService.h
                            #src/services/ServicesUnitTest.cpp
                            src/controllers/AppController.cpp
                            src/controllers/AppController.h
                            src/controllers/AppControllerTest.cpp
                            src/utils/Validation.cpp
                            src/utils/Validation.h)


enable_testing()
target_link_libraries(
        SIMS
        GTest::gtest_main
        /usr/local/lib/libgmock.a
        /usr/local/lib/libgmock_main.a)
include(GoogleTest)
gtest_discover_tests(SIMS)