#include<iostream>

void reference()
{
    /*
    You cannot have NULL references. 
    You must always be able to assume that a reference is connected to a legitimate piece of storage.

    Once a reference is initialized to an object, 
    it cannot be changed to refer to another object. 
    Pointers can be pointed to another object at any time.

    A reference must be initialized when it is created. 
    Pointers can be initialized at any time.
    */
   
    int a=12;
    int &r =a;
    std::cout<<"Variable \t"<<a<<"\n";
    std::cout<<"Reference \t"<<r<<"\n";
}

int main()
{
    reference();
}