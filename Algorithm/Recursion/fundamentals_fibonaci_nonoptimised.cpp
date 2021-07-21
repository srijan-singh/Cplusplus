/*
    Fibonacci Series
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

int fibonaci(int input)
{
    if (input == 0 or input == 1)
    {
        return input;
    }

    return fibonaci(input-1) + fibonaci(input -2);
}

int main()
{
    int input;
    cout<<"Enter the number: ";
    cin>>input;
    cout<<"Fibonaci Number: "<<fibonaci(input)<<endl;
    return 0;
}