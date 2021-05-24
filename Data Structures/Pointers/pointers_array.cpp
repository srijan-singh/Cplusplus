#include<iostream>

using std::string;

void array_of_int_pointers()
{
    std::cout<<"You are in array_of_int_pointers()\n";
    int length = 3;
    int arr_int[length]= {10,20,30};
    int *ptr_int[length]; //declairing the pointer of int data type
    
    for(int i=0; i<length; i++)
    {
        ptr_int[i] = &arr_int[i]; //assigning the address
    }

    for(int i=0; i<length; i++)
    {
        std::cout<<"Value at ["<<i<<"]\t"<<*ptr_int[i]<<"\n"; //value at respect index
    }
}

void array_of_string_pointers()
{
    std::cout<<"You are in array_of_string_pointers()\n";
    int length = 3;
    string arr_str[length] = {"Ram", "Krishna", "Budha"};
    string *ptr_str[length];

    for(int i=0; i<length; i++)
    {
        ptr_str[i] = &arr_str[i];
    }

    for(int i=0; i<length; i++)
    {
        std::cout<<"Value at ["<<i<<"]\t"<<*ptr_str[i]<<"\n";
    }
}

int main()
{
    array_of_int_pointers();
    array_of_string_pointers();
}