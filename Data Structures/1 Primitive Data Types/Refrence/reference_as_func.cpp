#include<iostream>

const int &sum(int &a, int &b)
{
    const int &add = (a+b);
    return add;
}

void reference_as_func()
{
    int a=12;
    int b=23;
    std::cout<<sum(a,b);
}

int main()
{
    reference_as_func();
}