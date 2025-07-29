//
// Created by oulashu on 2025/7/18.
//

#include "BaseView.h"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> // For system()

// --- Core Methods (The "UI Toolkit") ---

// Clears the entire console screen
void BaseView::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    // ANSI escape code for clearing the screen
    system("clear");
#endif
}

// Display a formatted message to the user (e.g., for errors or success notification)
void BaseView::showMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

// Pauses the application and waits for the user to press the Enter key
void BaseView::waitForKeyPress() const {
    showMessage("Press Enter to continue...");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // If the previous input was a number, a single ignore might not be enough.
    /*
    * Scenario: You enter a number and press the Enter key, then the system outputs the result to the user, 
    * subsequently calling waitForKeyPress() to await user confirmation. 
    * At this point, there will be two '\n' characters in the cin buffer.
    */
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
}

// Gets a raw line of text from the user. Ensures the input is not empty
std::string BaseView::getStringInput(const std::string& prompt) const {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            showMessage("Input cannot be empty. Please try again.");
        }
    } while (input.empty());
    return input;
}

// Gets an integer from the user. Ensures the input is a valid integer
int BaseView::getIntegerInput(const std::string& prompt) const {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        try {
            size_t pos;
            // pos: the first position that do not convert
            value = std::stoi(input, &pos);
            if (pos == input.length()) {
                return value;
            }
        } catch (const std::invalid_argument&) {
            // Not a number
        } catch (const std::out_of_range&) {
            // Number is too large or too small
        }
        showMessage("Invalid input. Please enter a valid integer.");
    }
}