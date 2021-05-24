#include <iostream>
#include <float.h>

using std::cout;

int main()
{
    float a; //Generally used to save memory
    double b = 7.7E4; //77000 = 7.7 x 10^4 //Mostly used
    long double c;
    cout<<b<<"\n";

    a = 10.0 /3;
    a = a * 1000000;
    cout<<a<<"\n"; //By default scientific notations
    cout<<std::fixed<<a<<"\n"; //fixing to our level

    //Significant digit the number will give trustworthy value

    cout<<FLT_DIG<<"\n";  //6
    cout<<DBL_DIG<<"\n";  //15
    cout<<LDBL_DIG<<"\n"; //18



    return 0; 
}