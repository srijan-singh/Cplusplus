#include <iostream>

using std::cin;
using std::cout;

double power(int base, int exponent)
{
    double result = 1;
    for(int i=0; i<exponent; i++)
    {
        result = result*base;        
    }
    return result;
}
void print(int base, int exponent)
{
    double result = power(base,exponent);
    cout<<base<<" to the power "<<exponent<<" is "<<result<<"\n";
}
int main()
{
    int base, exponent;
    cout<<"Input the base: \n";
    cin>>base;
    cout<<"Input the exponent: \n";
    cin>>exponent;
    print(base, exponent);
}