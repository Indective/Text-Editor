#include "TextEditor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

void TextEditor::newfile(const std::string filename)
{
    std::ofstream file(filename);
    std::string text;

    std::cout << "Enter your text in the new file : \n";
    std::getline(std::cin , text);
    file << text;

    file.close();
} 

void TextEditor::editfile(const std::string filename)
{
    std::fstream file;

    // Open the file for both reading and writing without truncating
    file.open(filename, std::ios::in | std::ios::out);

    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }

    std::string line;
    std::cout << "Current content of the file:\n";
    
    // Display the current content of the file
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    std::cout << "\nEnter new content (type END on a new line to finish):\n";
    std::string newContent;
    file.clear();  // Ensure that the output position is not affected by previous input
    file.seekp(0, std::ios::beg);  // Reset position to start of file

    // Start overwriting the file content
    while (true) {
        getline(std::cin, newContent);
        if (newContent == "END") break;
        file << newContent << std::endl;
    }

    file.close();

}

void TextEditor::removefile(const std::string filename)
{
    if( remove((filename).c_str()) != 0 )
     perror( "Error deleting file" );
  else
    puts( "File successfully deleted" );
}

void TextEditor::changecolor(int textColor, int bgColor)
{
    // Get the console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Calculate color attribute (foreground + background)
    int colorAttribute = (bgColor << 4) | textColor;
    
    // Set the color using Windows API
    SetConsoleTextAttribute(hConsole, colorAttribute);
}

void TextEditor::readfile(const std::string filename)
{
    std::string text;

    std::ifstream file(filename);

    while (getline (file, text)) 
    {
        std::cout << text;
    }   
    
    
    file.close(); 
}
