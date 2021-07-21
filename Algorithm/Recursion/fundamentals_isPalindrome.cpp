/*
    Palindrome
    Srijan Singh 
    20 July 2021
*/
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


bool isPalindrome(string input){

    if (input.length() == 0 or input.length() == 1)
    {
        return true;
    }

    int start_index = 0;
    int last_index = input.length()-1;

    if (input[start_index] == input[last_index])
    {
        return isPalindrome(input.substr(++start_index, --last_index));
    }

    return false;
}


int main()
{
    string input;
    cout<<"Enter the string: ";
    cin>>input;
    cout<<isPalindrome(input)<<endl;
    return 0;
}