cmake_minimum_required(VERSION 3.20)
project(ClionVersion)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClionVersion main.cpp
                            src/models/Student.cpp
                            src/models/Student.h
                            src/models/Course.cpp
                            src/models/Course.h
                            src/models/EnrollmentRecord.cpp
                            src/models/EnrollmentRecord.h
                            src/repositories/IStudentRepository.h
        src/repositories/InMemoryStudentRepository.cpp src/repositories/InMemoryStudentRepository.h)
