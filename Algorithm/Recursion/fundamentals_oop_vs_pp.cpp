/*
    Object Oriented Programming vs Procedural Programming
    Srijan Singh 
    20 July 2021
*/
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Recursion{
    
    public:
    
    string A()
    {
        return "hello " + B();
    }

    string B()
{
    return "my " + C();
}
    
    string C()
    {
        return "friends";
    }

};

string C()
    {
        return "friends";
    }

string B()
{
    return "my " + C();
}
    
string A()
{
    return "hello " + B();
}


int main()
{
    cout<<A()<<endl;

    Recursion r;
    cout<<r.A();
    return 0;
}