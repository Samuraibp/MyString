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
    MyString(const MyString& other);
    ~MyString();
    void setStr(const char* s);
    int Getlength() const;
    const char* Getstr() const;
    void input();
    void print() const;
    void Mystrcpy(MyString& obj);
    bool Mystrstr(const char* str);
    int MyChar(char c);
    int Mystrlen();
    void MyStrCat(MyString& b);
    void MySteDel(char c);
    int MyStrCmp(MyString& b);
    char& operator()();
    MyString& operator++();      
    MyString operator++(int);    
    char& operator[](int index);
    const char& operator[](int index) const;
    MyString& operator=(MyString& b);
    MyString operator+(char c) const;
    MyString operator+(int n) const;
};

ostream& operator<<(std::ostream& out, const MyString& obj);
istream& operator>>(std::istream& in, MyString& obj);
MyString operator+(char c, const MyString& obj);
MyString operator+(int n, const MyString& obj);
