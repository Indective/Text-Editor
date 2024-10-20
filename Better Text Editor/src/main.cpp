#include "TextEditor.h"
#include <iostream>
#include <string>
#include <filesystem>

void displayMenu();
char getValidInput();
bool confirmExit();

int main() {
    TextEditor editor;
    bool exitProgram = false;
    std::string filename;
    int bgcolor; 
    int textcolor;

    while (!exitProgram) {
        displayMenu();
        char choice = getValidInput();

        // Clear the input buffer after reading a single character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                std::cout << "Enter file name: ";
                std::getline(std::cin, filename); // To handle spaces in file names
                editor.newfile(filename);
                break;
            case '2':
                std::cout << "Enter file name: ";
                std::getline(std::cin, filename);
                editor.readfile(filename);
                break;
            case '3':
                std::cout << "Enter file name: ";
                std::getline(std::cin, filename);
                editor.editfile(filename);
                break;
            case '4':
                std::cout << "You chose to delete a file.\n";
                break;
            case '5':
                std::cout << "List of colors (Foreground & Background) \n";
                std::cout << "0 = Black, 1 = Blue, 2 = Green, 3 = Aqua, 4 = Red, 5 = Purple, \n";
                std::cout << "// 6 = Yellow, 7 = White, 8 = Gray, 9 = Light Blue, 10 = Light Green, \n";
                std::cout << "// 11 = Light Aqua, 12 = Light Red, 13 = Light Purple, 14 = Light Yellow, 15 = Bright White \n";

                std::cout << "Enter text color : ";
                std::cin >> textcolor;

                std::cout << "\nEnter Background color : ";
                std::cin >> bgcolor;

                editor.changecolor(textcolor, bgcolor);
                break;
            case '6':
                if (confirmExit()) {
                    exitProgram = true;
                    std::cout << "Exiting the program. Goodbye!\n";
                }
                break;
            default:
                std::cout << "Unknown error.\n";
        }
    }

    return 0;
}


void displayMenu() {
    std::cout << "\n===== Indective's Text Editor =====\n";
    std::cout << "All rights reserved to the Indective Corporation 2024.\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Please choose an option:\n";
    std::cout << "1) Create a new file\n";
    std::cout << "2) Read from an existing file\n";
    std::cout << "3) Edit an existing file\n";
    std::cout << "4) Delete a file\n";
    std::cout << "5) Change text editor color\n";
    std::cout << "6) Exit\n";
    std::cout << "-----------------------------------\n";
}

char getValidInput() {
    char choice;
    std::cout << "Enter your choice (1-6): ";
    std::cin >> choice;
    while (choice < '1' || choice > '6') {
        std::cout << "Invalid choice. Please enter a number between 1 and 6: ";
        std::cin >> choice;
    }
    return choice;
}

bool confirmExit() {
    char ext;
    std::cout << "Are you sure you want to exit? (Y/N): ";
    std::cin >> ext;
    return tolower(ext) == 'y';
}