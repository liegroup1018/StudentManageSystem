//
// Created by oulashu on 2025/7/18.
//

#ifndef CLIONVERSION_MAINVIEW_H
#define CLIONVERSION_MAINVIEW_H

#include "BaseView.h"

class MainView : public BaseView{
public:
    // Dispalys the main menu(Student, Course, Enrollment, Exit)
    // and returns the user's input
    int showMainMenu();
};


#endif //CLIONVERSION_MAINVIEW_H
