#include<iostream>

using std::ios;
using std::cout;
using std::endl;

int main()
{
    auto boolVar = true;
    auto intVar = 11;
    auto doubleVar = 3.1451;
    auto charVar = 'S';
    auto stringVar = "Srijan";

    cout.setf(ios::boolalpha);
    
    cout<<boolVar<<endl;
    cout<<intVar<<endl;
    cout<<doubleVar<<endl;
    cout<<charVar<<endl;
    cout<<stringVar;
    
    return 0;

}