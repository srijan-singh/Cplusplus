#include <iostream>

int factorail(int value)
{
    //Base Case/Termination Case
    // 1! = 1 and 0! = 1
    if(value <= 1)
    {
        return 1;
    }
    // n! = n * (n-1)!
    return value * factorail(value-1);
}

int main()
{
    std::cout<<factorail(4);
}