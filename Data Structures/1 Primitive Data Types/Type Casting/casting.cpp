#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string num1, num2;
    cout<<"Enter a number: ";
    cin>>num1;
    cout<<"Enter another number: ";
    cin>>num2;

    int nNum1 = stoi(num1);
    int nNum2 = stoi(num2);
    printf("%d + %d = %d", nNum1,nNum2,(nNum1+nNum2));
    
    return 0;

}