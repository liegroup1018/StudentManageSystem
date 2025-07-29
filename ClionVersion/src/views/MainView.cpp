#include "MainView.h"
#include <iostream>

int MainView::showMainMenu() {
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Student" << std::endl;
    std::cout << "2. Course" << std::endl;
    std::cout << "3. Enrollment" << std::endl;
    std::cout << "4. Exit" << std::endl;
    int input = getIntegerInput("Enter your choice: ");
    return input;
}