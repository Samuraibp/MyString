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

    ~MyString() {
        delete[] str;
    }

    void input();

    void print() const;
};

