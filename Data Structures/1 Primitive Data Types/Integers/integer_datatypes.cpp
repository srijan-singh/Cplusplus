#include <iostream> 
#include <climits> //To determine the max and minimum value we can accomodate in a data type

using std::cout;
using std::endl;


void display_signed(); //To display max and min value of signed integers datatypes

void display_unsigned(); //To display max value of unsigned integers datatypes

//We're using sizeof() operator to determine the size of the integer datatypes

int main()
{
    // short <= int <= long <= long long
    short a; 
    long b;
    long long c;
    //Unsigned allows only positive integer type!
    unsigned short aa;
    unsigned long bb;
    unsigned long long cc;

    //Size of datatypes in bytes 
    cout<<sizeof(short)<<endl;        //2 bytes = 16 bits
    cout<<sizeof(long)<<endl;       //4 bytes = 32 bits
    cout<<sizeof(long long)<<endl; //8 bytes = 64 bits

    display_signed();   //Function To Tell the Min and Max Value of signed data types
    display_unsigned(); //Function To Tell Max Value of unsigned int data types

    return 0;
}

//DATATYPES_MAX/MIN is used to describe the max/min value of the data structures

void display_signed() //Function To Tell the Min and Max Value of the data types
{
    cout<<"Signed Int Data Types"<<endl;
    //Short or 16 Bits Int
    cout<<"The Min value of Short or 16 Bits Int: "<<INT16_MIN<<endl<<"The Max value of Short or 16 Bits Int: "<<INT16_MAX<<endl;
    //Long or 32 Bits Int or Regular Int
    cout<<"The Min value of Signed Long or 32 Bits Int: "<<INT32_MIN<<endl<<"The Max value of Signed Long or 32 Bits Int: "<<INT32_MAX<<endl;
    //Long Long or 64 Bits Int 
    cout<<"The Min value of Signed Long Long or 64 Bits Int: "<<INT64_MIN<<endl<<"The Max value of Signed Long Long or 64 Bits Int: "<<INT64_MAX<<endl;
}
void display_unsigned() //Function To Tell Max Value of unsigned int data types
{  
    //The Default Value of Min Unsigned Integer Datatypes is zero
    cout<<"Unsigned Int Data Types"<<endl;
    //Short or 16 Bits Int
    cout<<"The Max value of Unsigned Short or 16 Bits Int: "<<UINT16_MAX<<endl;
    //Long or 32 Bits Int or Regular Int
    cout<<"The Max value of Unsigned Long or 32 Bits: "<<UINT32_MAX<<endl;
    //Long Long or 64 Bits Int
    cout<<"The Max value of Unsigned Long Long or 64 Bits: "<<UINT64_MAX<<endl;
}