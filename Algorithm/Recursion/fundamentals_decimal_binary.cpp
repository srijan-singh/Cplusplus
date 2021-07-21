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


string decimalToBinary(int input, string output = "")
{

    if (input == 0)
    {
        if (output == "")
        {
            return "0";
        }
        
        return output;
    }
    
    string remainder = to_string(input%2);
    
    output.insert(0, remainder);
    
    return decimalToBinary(input/2, output);
}

int main()
{
    int input;
    cout<<"Enter the number: ";
    cin>>input;
    cout<<"Binary: "<<decimalToBinary(input)<<endl;
    return 0;
}