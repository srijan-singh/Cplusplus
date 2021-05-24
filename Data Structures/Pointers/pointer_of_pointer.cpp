#include<iostream>

void pointer_of_pointer()
{
    int a=10;
    int *ptr = &a;
    int **ptr_ptr = &ptr;

    std::cout<<"Variable          \t"<<a<<"\n";
    std::cout<<"Pointer           \t"<<*ptr<<"\n";
    std::cout<<"Pointer of Pointer\t"<<**ptr_ptr<<"\n";
}

int main()
{
    pointer_of_pointer();
}