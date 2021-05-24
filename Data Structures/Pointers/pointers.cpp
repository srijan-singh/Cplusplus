#include<iostream>

int main()
{
    int a = 12;
    //Pointer of int data type
    int *p1;
    //Pointing to address of variable
    p1 = &a;

    //Variable Address
    std::cout<<"&Var "<<"\t"<<&a;
    //Pointed Address
    std::cout<<"P "<<"\t"<<p1<<"\n";
    //Variable Value
    std::cout<<"Var"<<"\t"<<a<<"\n";
    //Value on Pointed Address
    std::cout<<"*P "<<"\t"<<*p1<<"\n";
    
    

    return 0;
}