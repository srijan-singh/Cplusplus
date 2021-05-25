#include <iostream>

using std::cout;
using std::ios;

int main()
{
    int num =10;
    bool result = (num % 2 ==0) ? true:false;
    cout.setf(ios::boolalpha); //To print true or false
    cout<<result<<"\n";
    return 0;
}