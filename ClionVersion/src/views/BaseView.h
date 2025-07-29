//
// Created by oulashu on 2025/7/18.
//

#ifndef CLIONVERSION_BASEVIEW_H
#define CLIONVERSION_BASEVIEW_H

#include <string>

class BaseView {
public:
    virtual ~BaseView() = default;

public:
    // This class doesn't need data members. Its state is the console itself

    // --- Core Methods (The "UI Toolkit") ---

    // Clears the entire console screen
    virtual void clearScreen() const;

    // Display a formatted message to the user(e.g., for errors or success notification)
    virtual void showMessage(const std::string& message) const;

    // Pauses the application and waits for the user to press the Enter key
    virtual void waitForKeyPress() const;

protected:
    // Gets a raw line of text from the user. Ensures the input is not empty
    virtual std::string getStringInput(const std::string& prompt) const;

    // Gets a integer from the user. Ensures the input is a valid integer
    virtual int getIntegerInput(const std::string& prompt) const;

};


#endif //CLIONVERSION_BASEVIEW_H