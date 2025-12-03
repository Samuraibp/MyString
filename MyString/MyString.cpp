#include "MyString.h"

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

void MyString::input()
{
    cout << "Enter a line (max " << length << " symbols): ";
    cin.getline(str, length + 1);
}

void MyString::print() const
{
    cout << str << std::endl;
}
