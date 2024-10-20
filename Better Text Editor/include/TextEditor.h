#include<iostream>

#ifndef FILEORGANIZER_H
#define FILEORGANIZER_H

class TextEditor {
public:
    void newfile(const std::string filename);
    void editfile(const std::string filename);
    void removefile(const std::string filename);
    void changecolor(int textColor, int bgColor);
    void readfile(const std::string filename);

};

#endif