#pragma once
#include <iostream>
using namespace std;
class MyString
{
	char* str; 
	int length;
public:
    MyString();
    MyString(int n);
    MyString(const char* input);
    ~MyString();
    void input();
    void print() const;
    void Mystrcpy(MyString& obj);
    bool Mystrstr(const char* str);
    int MyChar(char c);

};

