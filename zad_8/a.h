#ifndef LABORATORIUM_A_H
#define LABORATORIUM_A_H

#include <string>
#include <string.h>
#include <cstdio>
#include <iostream>

class A
{
public:
    A()
    {
        mText = nullptr;
    }
    A(const std::string &text)
    {
        mText = new char[text.size() + 1];
        text.copy(mText, text.size() + 1);
        mText[text.size()] = '\0';
    }
    A(const A &object)
    {
        std::cout << "Copy constructor\n"; //check
        this->mText = new char[strlen(object.mText) + 1];
        strcpy(this->mText, object.mText);
    }
    A(A&& object) noexcept
    {
        std::cout << "Move constructor\n"; //check
        this->mText = object.mText;
        object.mText = nullptr;
    }
    char* get()
    {
        return mText;
    }
    ~A() {delete [] mText;}
private:
    char *mText;
};

#endif //LABORATORIUM_A_H
