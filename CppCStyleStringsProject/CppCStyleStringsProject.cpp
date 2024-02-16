#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

unsigned int StringLength(const char* str);

void StringCopy(char*& dest, const char* source);

void StringConcat(char*& dest, const char* source);

int main()
{
    const char* snum = "123";
    int num = atoi(snum);

    const char* cstr = "Hello World";

    std::cout << std::boolalpha << (bool)isalpha('1') << "\n";

    std::cout << (char)tolower('A') << "\n";

    char* str = new char;
    
    StringCopy(str, cstr);
    //StringCopy(str, "Hello World");
        
    std::cout << str << "\n";

    StringConcat(str, " Hello People");

    std::cout << str << "\n";


    char* s1 = new char;
    //strcpy(s1, "Hello");
    strcpy_s(s1, strlen("Hello") + 1, "Hello");

    std::cout << s1 << "\n";
}

unsigned int StringLength(const char* str)
{
    unsigned int length{};
    while (str[length])
        length++;
    return length;
}


void StringCopy(char*& dest, const char* source)
{
    delete[] dest;
    dest = new char[StringLength(source) + 1];
    
    int index{};
    while (source[index])
        dest[index] = source[index++];
    
    dest[index] = '\0';
}




void StringConcat(char*& dest, const char* source)
{
    const char* oldStr = dest;

    dest = new char[StringLength(dest) + StringLength(source) + 1];
    
    int index{};
    
    for (int i{}; i < StringLength(oldStr); i++)
        dest[index++] = oldStr[i];
    
    for (int i{}; i < StringLength(source); i++)
        dest[index++] = source[i];

    dest[index] = '\0';

    delete[] oldStr;
}
