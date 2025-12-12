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

MyString::MyString(const MyString& other): str(new char[other.length + 1]), length(other.length)
{
    strcpy(str, other.str);
}


MyString::~MyString()
{
    delete[] str;
}

MyString::MyString(MyString&& other)
{
    str = other.str;      
    length = other.length;

    other.str = nullptr;   
    other.length = 0;
}

void MyString::setStr(const char* s)
{
    if (!s) {
        str = new char[1];
        str[0] = '\0';
        length = 0;
        return;
    }
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

int MyString::Getlength() const
{
    return length;
}

const char* MyString::Getstr() const
{
    return str;
}

void MyString::input()
{
    cout << "Enter a line (max " << length << " symbols): ";
    cin.getline(str, length + 1);
}

void MyString::print() const
{
    cout << str << endl;
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

int MyString::Mystrlen()
{
    return length;
}

void MyString::MyStrCat(MyString& b)
{
    int newLength = length + b.length;
    char* newStr = new char[newLength + 1];
    for (int i = 0; i < length; i++)
        newStr[i] = str[i];
    for (int i = 0; i < b.length; i++)
        newStr[length + i] = b.str[i];
    newStr[newLength] = '\0';
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MySteDel(char c)
{
    int count = 0;
    for (int i = 0; i < length; i++)
        if (str[i] == c)
            count++;

    if (count == 0)
        return;

    int newLength = length - count;
    char* newStr = new char[newLength + 1];

    int j = 0;

    for (int i = 0; i < length; i++) {
        if (str[i] != c)
        {
            newStr[j++] = str[i];
        }
        else continue;
    }

    newStr[newLength] = '\0';
    delete[]str;
    str = newStr;
    length = newLength;
}

int MyString::MyStrCmp(MyString& b)
{
    int minLen = (length < b.length ? length : b.length);

    for (int i = 0; i < minLen; i++)
    {
        if (str[i] < b.str[i])
            return -1;

        if (str[i] > b.str[i])
            return 1;
    }

    if (length < b.length)
        return -1;

    if (length > b.length)
        return 1;

    return 0; 
}

MyString& MyString::operator=(MyString&& other)
{
    if (this != &other)
    {
        delete[] str;       
        str = other.str;    
        length = other.length;

        other.str = nullptr; 
        other.length = 0;
    }
    return *this;
}

char& MyString::operator()()
{
    char c;
    cin >> c;

    delete[] str;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
    length = 1;

    return str[0];
}


MyString& MyString::operator++()
{
    char add = '*';  

    char* newStr = new char[length + 2];
    newStr[0] = add;

    for (int i = 0; i < length; i++)
        newStr[i + 1] = str[i];

    newStr[length + 1] = '\0';

    delete[] str;
    str = newStr;
    length++;
    return *this;
}

MyString MyString::operator++(int)
{
    MyString temp(*this); 
    char add = '+';       
    char* newStr = new char[length + 2];
    for (int i = 0; i < length; i++)
        newStr[i] = str[i];

    newStr[length] = add;
    newStr[length + 1] = '\0';

    delete[] str;
    str = newStr;
    length++;

    return temp;
}

char& MyString::operator[](int index)
{
    return str[index];
}

const char& MyString::operator[](int index) const
{
    return str[index];
}

MyString& MyString::operator=(MyString& b)
{
    if (this == &b) return *this;

    delete[] str;

    length = b.length;
    str = new char[length + 1];

    for (int i = 0; i < length; i++)
        str[i] = b.str[i];

    str[length] = '\0';

    return *this;
}

MyString MyString::operator+(char c) const
{
    MyString temp;
    temp.length = length + 1;
    temp.str = new char[temp.length + 1];

    for (int i = 0; i < length; i++) temp.str[i] = str[i];
    temp.str[length] = c;
    temp.str[temp.length] = '\0';

    return temp;
}

MyString MyString::operator+(int n) const
{
    MyString temp;
    temp.length = length + n;
    temp.str = new char[temp.length + 1];

    for (int i = 0; i < length; i++) temp.str[i] = str[i];
    for (int i = 0; i < n; i++) temp.str[length + i] = '*';
    temp.str[temp.length] = '\0';

    return temp;
}

ostream& operator<<(std::ostream& out, const MyString& obj)
{
    out << obj.Getstr();
    return out;
}

istream& operator>>(std::istream& in, MyString& obj)
{
    char buffer[1000];
    in >> buffer;
    obj.setStr(buffer);
    return in;
}

MyString operator+(char c, const MyString& obj)
{
    MyString temp(obj.Getlength() + 1);  

    char* buffer = new char[obj.Getlength() + 2]; 

    buffer[0] = c; 

    const char* s = obj.Getstr();
    for (int i = 0; i < obj.Getlength(); i++)
        buffer[i + 1] = s[i];

   

    temp.setStr(buffer); 

    delete[] buffer;

    return temp;
}

MyString operator+(int n, const MyString& obj)
{
    MyString temp;
  
    char* buffer = new char[obj.Getlength() + n + 1];
    const char* s = obj.Getstr();
    for (int i = 0; i < n; i++) buffer[i] = '*';
    for (int i = 0; i < obj.Getlength(); i++) buffer[n + i] = s[i];
    buffer[obj.Getlength() + n] = '\0';

    temp.setStr(buffer);
    delete[]buffer;
    return temp;
}






