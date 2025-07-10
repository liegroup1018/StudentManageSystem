# 基本架构

**采用 Layered Architecture + MVC 模式**

1. **Domain Objects (or Entities):** These are pure data classes. They hold state but have no logic about how they are saved or manipulated.
    - `Student`
    - `Course`
    - `Enrollment`
2. **Repository Layer (Data Access Layer - DAL):** This layer's _only_ responsibility is to communicate with the data source (a database, a file, or in our case, an in-memory `std::vector`). It performs basic CRUD (Create, Read, Update, Delete) operations.
    - `StudentRepository`: Handles saving, finding, deleting `Student` objects.
    - `CourseRepository`: Handles saving, finding, deleting `Course` objects.
    - `EnrollmentRepository` : Handles saving, finding, deleting `Enrollment` objects.
3. **Service Layer (Business Logic Layer - BLL):** This is the heart of your application's logic. It orchestrates operations by using one or more repositories. This is where rules like "a student cannot enroll in a course that is full" or "a student cannot enroll in more than 5 courses" would live.
    - `StudentManagementService`: Contains methods like `enrollStudentInCourse(studentId, courseId)`, which would use both the `StudentRepository` and `CourseRepository`.

将上面的三个层级整合到 MVC 结构中

- The **Controller** talks to the **Service Layer**.
- The **Service Layer** uses the **Repository Layer** to get data.
- The **Repository Layer** deals with the underlying storage and returns **Domain Objects**.

![[SIS 架构图.png]]


>[!note] MVC
>**Model-View-Controller (MVC)** is a pattern for the presentation layer.
>- **Model**: Represents the application's data and business rules. It's the "brain" of the application (e.g., Student, Course classes).
>- **View**: The user interface (UI). In our case, this is the console output and input handler. It's responsible for displaying data.
>-  **Controller**: Handles user input, interacts with the Model, and tells the View what to display. It acts as the coordinator.
        

> [!NOTE] **Layered Architecture**
>         
> - **Layered Architecture** organizes the entire application into horizontal layers, where each layer has a specific responsibility. A common structure is:
>     
>     - **Presentation Layer**: The MVC components reside here.
>         
>     - **Service Layer (or Business Logic Layer)**: Contains the core business logic. It orchestrates calls to the data layer. This keeps controllers clean.
>         
>     - **Data Access Layer (DAL or Repository Layer)**: Responsible for all communication with the data source (e.g., text files, a database). It abstracts the data storage details.


# 代码目录结构

```text
student-management-system/
├── data/                  # Data storage files
│   ├── students.csv
│   ├── courses.csv
│   └── enrollments.csv
│
├── src/                   # All source code
│   ├── models/            # Model classes (data structures)
│   │   ├── Student.h
│   │   ├── Course.h
│   │   └── Enrollment.h
│   │
│   ├── views/             # View classes (console I/O)
│   │   ├── MainView.h
│   │   ├── MainView.cpp
│   │   ├── StudentView.h
│   │   └── StudentView.cpp
│   │
│   ├── controllers/       # Controller classes (user input handlers)
│   │   ├── AppController.h
│   │   └── AppController.cpp
│   │
│   ├── services/          # Service classes (business logic)
│   │   ├── StudentService.h
│   │   └── StudentService.cpp
│   │
│   └── repositories/      # Repository classes (data access)
│       ├── StudentRepository.h
│       ├── StudentRepository.cpp
│       ├── CourseRepository.h
│       └── CourseRepository.cpp
│
└── main.cpp               # Application entry point
```

## Function of each directory

- `data/`: Stores the application's data. Using .csv (Comma-Separated Values) is simple and human-readable.
    - students.csv: 1,Alice
    - courses.csv: 101,Introduction to C++
    - enrollments.csv: 1,101 (student with ID 1 is enrolled in course with ID 101)
- `src/models/`: Contains simple data structures (often just structs or classes with public members) that represent the core entities of your application. They don't contain business logic.
- `src/views/`: Handles all console interaction (std::cout, std::cin). It displays menus, prompts for input, and shows results.
- `src/controllers/`: The link between the View and the Service layer. It takes user choices from the View and calls the appropriate service methods.
- `src/services/`: Implements the application's business rules. For example, "find all courses for a student" is a business operation that requires coordinating multiple data sources.
- `src/repositories/`: Manages reading from and writing to the .csv files. This layer completely hides the fact that we are using files. If you later switch to a database, you only need to change this layer.
- `main.cpp`: The starting point. Its only job is to create the necessary objects and start the main application loop.

# Feature list

1.  **Student Management:**
    *   Add new student
    *   View student details
    *   Update student details
    *   Delete student (consider implications)
    *   Search for students (by ID, name, etc.)
    *   List all students
2.  **Course Management:**
    *   Add new course
    *   View course details
    *   Update course details
    *   Delete course (consider implications)
    *   Search for courses (by ID, name, code)
    *   List all courses
3.  **Enrollment Management:**
    *   Enroll a student in a course
    *   Unenroll a student from a course
    *   View students enrolled in a specific course
    *   View courses a specific student is enrolled in
4.  **Grade Management:**
    *   Assign/update a grade for a student in a course
    *   View grades for a specific student (transcript-like)
    *   View grades for a specific course (class performance)
    *   计算指定学生的 GPA
5.  ~~**Reporting (Basic):**~~
    *   ~~Generate student transcript~~
    *   ~~Generate course roster with grades~~
    *   ~~List students by major/program (if we add this)~~
6.  **System Features:**
    *   Data Persistence (Save and Load data from/to a file)
    *   User Interface (Console-based for C++)
    *   Input Validation & Error Handling
    *   ~~(Optional Advanced) User Authentication & Roles (Admin, Student, Faculty) - Let's keep this out for a basic version.~~
# Core Entity

##  model 相关的类

1.  **Student Information:**
    *   **Unique Student ID:**  - *Primary Key*
        * 这里使用 S + 随机六位数字（例如 S202989）作为学生 ID
    *   **Full Name:** (Could be First Name, Middle Name, Last Name)
    *   **Level**: 具体年级

2.  **Course Information:**
    *   **Unique Course ID:** - *Primary Key*
        * 这里使用 C + 随机六位数字（例如 C090874）作为课程 ID
    *   **Course Name:** (e.g., "Introduction to Programming", "Data Structures")
    *   **Course Code:** (e.g., "CS101", "MA202") - *Often used for display*
    *   **Description:** (Optional, brief overview)

3.  **Enrollment Information (Linking Students and Courses):**
    *   This is crucial because a student can take many courses, and a course can have many students (Many-to-Many relationship).
    *   **Student ID (Foreign Key):** Links to a `Student`
    *   **Course ID (Foreign Key):** Links to a `Course`
    *   **Grade/Mark:** (e.g., 'A', 'B+', 85%) - *Can be initially empty/null*
    *   **Semester/Term of Enrollment:** (e.g., "Fall 2023")

4.  ~~**System/Administrative Information (Less direct, more for management):**~~
    *   ~~Last save date/time (if implementing persistence~~

## View 相关的类

1. **MainView**: the application's main UI router. (as the homepage and main navigation bar of a website. It directs the user to different sections but doesn't contain the detailed content of those sections.)
	- **Displaying the Main Menu:** It shows the primary navigation options like "1. Manage Students", "2. Manage Courses", "0. Exit".
	- **Handling Top-Level Input:** It's responsible for getting the user's choice from that main menu.
	- **Displaying Generic Messages:** It can handle application-wide messages like "Goodbye!", "Invalid choice, please try again.", or "Saving data...".

2. **StudentView**: a specialized, entity-specific view. Its sole responsibility is to handle all UI related to the Student model.
	- **Displaying a List of Students:** It knows how to format and print a table of all students.
	- **Displaying a Single Student's Details:** It can show a detailed "profile" for one student, including their ID, name, and the courses they are enrolled in.
	- **Prompting for Student Data:** It handles the specific "forms" for creating or updating a student, asking for "Enter student name:", etc.

3. **BaseView**: 基类，包含所有 View 都需要的功能
	*   Clear the console screen.
	*   Display a generic message or error.
	*   Pause and wait for the user to press Enter.
	*   Get validated user input (like a number or a non-empty string).

4. **class Validation**: 专门用于检测用户输入的数据是否正确
	* static bool isValidStudentIdFormat(const string& id);
	* static bool isValidCourseIdFormat(const string& id);
	* static bool isValidNameFormat(const string& id);
	* ....
## Control 相关的类

1. `AppController`：
	- hold instances of *all* the views it needs to manage
	- 包含 StudentService 实例
## Service 相关的类

1. **StudentService**: 专门用于处理学生相关的服务

2. **CourseService**: 专门用于处理课程相关的服务

3. **EnrollmentService:** 专门用于处理学生登记相关的服务


## Repository 相关

repositories can refer to databases, files, or caches such as `std::vector`.

**基本思路**：Use separate repository classes for each of core data entities, 所以有 9 个相关的类，这里只列出学生相关作为例子，其它的同理

1. **IStudentRepository**：defines the "contract" for any student repository. It contains pure virtual functions (`= 0`), which means any class that inherits from it *must* provide an implementation

2. **FileStudentRepository**：信息存储在文件中，需要从文件中读取信息或者将信息写入到文件中
   
3. **InMemoryStudentRepository**：信息存储在缓存中，例如 std::vector 中

>[!note]
>设计假设：当前设计中，程序仅从单一类型的仓库读取数据，不存在多级查询逻辑（例如若缓存未命中则转而查询文件系统的情况）。
# int main() 实现

大致的代码框架

```CPP
// main.cpp
#include "src/repositories/StudentRepository.h"
#include "src/repositories/CourseRepository.h"
#include "src/repositories/EnrollmentRepository.h"
#include "src/services/StudentService.h"
#include "src/views/MainView.h"
#include "src/controllers/AppController.h"
#include <iostream>

int main() {
    try {
        // 1. Create Repository instances (Data Access Layer)
        // These objects know how to read/write data from files.
        StudentRepository studentRepo("data/students.csv");
        CourseRepository courseRepo("data/courses.csv");
        EnrollmentRepository enrollmentRepo("data/enrollments.csv");

        // 2. Create Service instance (Business Logic Layer)
        // Inject repositories into the service. The service doesn't know about files,
        // it only knows about repositories.
        StudentService studentService(studentRepo, courseRepo, enrollmentRepo);

        // 3. Create View and Controller instances (Presentation Layer)
        // Inject the service and view into the controller.
        MainView mainView;
        AppController appController(studentService, mainView);

        // 4. Start the application
        appController.run();

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
```

# 仓库类编写注意点
## 使用文件存储数据

这里使用一个简单的实现：
1. 初始化的时候打开文件，并把文件写入到 vector 中。
2. 析构的时候首先清空文件中的内容，然后再把 vector 中的数据写入到文件中

使用 csv 格式存储数据
```text
StudentId,Name,Level
S039482,James Smith,3
S712345,Jennifer Garcia,2
S198237,Robert Wilson,4
S563289,Mary Rodriguez,1
S874563,David Martinez,3
```

当前CSV文件格式特点
1. 第一行是列标题
2. 每行代表一条记录
3. 记录中的字段用逗号分隔
4. 字段中不包含引号逗号只会包含空格

### **未考虑问题**
- 多线程场景