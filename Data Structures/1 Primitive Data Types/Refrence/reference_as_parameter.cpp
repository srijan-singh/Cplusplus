#include<iostream>

int sum(int &a, int &b)
{
    return a+b;
}

void reference_as_parameter()
{
    int a=12;
    int b=23;
    std::cout<<sum(a,b);
}

int main()
{
    reference_as_parameter();
}