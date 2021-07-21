/*
    Decimal To Binary
    Srijan Singh 
    20 July 2021
*/
#include <iostream>
#include <string>

using std::string;
using std::to_string;
using std::cout;
using std::cin;
using std::endl;

int sumOfNumber(int input)
{
    if(input==1)
    {
        return 1;
    }

    return input + sumOfNumber(input - 1);
}

int main()
{
    int input;
    cout<<"Enter the number: ";
    cin>>input;
    cout<<"Sum: "<<sumOfNumber(input)<<endl;
    return 0;
}