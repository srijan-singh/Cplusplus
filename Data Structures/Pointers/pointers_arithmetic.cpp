#include<iostream>

void pointers_arithmetic()
{
    int arr[]={12,23,34};
    int *p;
    p = arr;

    std::cout<<"Increament\n";
    for (int i = 0; i<3; i++)
    {
        std::cout<<"Address of ["<<i<<"]\t"<<p<<"\n";
        std::cout<<"Value of ["<<i<<"]\t"<<*p<<"\n";
        ++p;
    }
    std::cout<<"Decreament\n";

    for (int i = 3; i>-1; i--)
    {
        std::cout<<"Address of ["<<i<<"]\t"<<p<<"\n";
        std::cout<<"Value of ["<<i<<"]\t"<<*p<<"\n";
        --p;
    }
}
int main()
{
    pointers_arithmetic();
}