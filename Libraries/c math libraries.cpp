#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    cout<<sqrt(25)<<"\n";                //Square root function
    cout<<pow(5,2)<<"\n";                //Power
    cout<<remainder(10, 3.25)<<"\n";     //Remainder
    cout<<fmod(10, 3.25)<<"\n";          //Float Modulous
    cout<<fmax(10, 9)<<"\n";             //Maximim
    cout<<fmin(2, 9)<<"\n";              //Minimum
    cout<<ceil(-3.25)<<"\n";             //Rounding to bigger number
    cout<<floor(-3.25)<<"\n";            //Rounding to smaller number
    cout<<trunc(-3.25)<<"\n";            //Removing the decimal
    cout<<round(3.25)<<"\n";             //Rounding off

    cout<<NAN<<"\n";
    cout<<INFINITY<<"\n";
    cout<<-INFINITY<<"\n";
    return 0;
}

// Some keyword s
// nan: not a number
// inf: infinity
// -inf: negative infinity