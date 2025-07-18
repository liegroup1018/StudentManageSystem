-- from Gemini

# Version-1

目前的 View 主要包括四个类
- MainView: 表示主页面
- StudentView: 表示处理学生相关信息的页面
- CourseView: 表示处理课程相关信息的页面
- EnrollmentView: 表示处理登记相关信息的页面

使用 BaseView 作为这四种类的基类，有如下好处
- reuse code
- 确保一致性：providing a standard way to perform UI tasks
- 增加可维护性：allowing you to fix a UI bug or change a behavior in just one place

