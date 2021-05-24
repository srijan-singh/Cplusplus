#include<iostream>

int *pointer_as_func()
{
    int var = 12;
    int *ptr;
    ptr = &var;
    return ptr;    
}

int main()
{
    std::cout<<pointer_as_func();
}