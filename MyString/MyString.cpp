#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
}

MyString::MyString(int n)
{
    length = n;
    str = new char[length + 1];
    str[0] = '\0';
}

MyString::MyString(const char* input)
{
    length = strlen(input);
    str = new char[length + 1];
    strcpy(str, input);
}

MyString::~MyString()
{
    delete[] str;
}

void MyString::input()
{
    cout << "Enter a line (max " << length << " symbols): ";
    cin.getline(str, length + 1);
}

void MyString::print() const
{
    cout << str << std::endl;
}

void MyString::Mystrcpy(MyString& obj)
{
    if (this == &obj) return;

    delete[] str;

    length = strlen(obj.str);
    str = new char[length + 1];

    strcpy(str, obj.str);
}

bool MyString::Mystrstr(const char* str)
{
    if (!str || !this->str) return false;

    return strstr(this->str, str) != nullptr;
}

int MyString::MyChar(char c)
{
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == c)
            return i;
    }
    return -1;
}



