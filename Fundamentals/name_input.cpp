#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::cin;

int main()
{
    string name;
    cout<<"Enter your name: ";
    cin>>name;
    if (name.compare("Srijan")==0)
    {
        cout<<"Welcome "<<name;
    }
    else
    {
        cout<<"Welcome Imposter";
    }
    return 0;
}