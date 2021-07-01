#include<iostream>

int sum(int num1, int num2=0)// Call by Value and Default Parameter.
{
    return num1+num2;
}

int product(int *num1, int num2) // Call by Reference and Call by Value.
{
    return (*num1)*num2;
}

int main()
{
    int num1 = 73;
    int num2 = 68;
    std::cout<<sum(num1)<<"\n";
    std::cout<<sum(num1, num2)<<"\n";
    std::cout<<product(&num1, num2);
    return 0;
}