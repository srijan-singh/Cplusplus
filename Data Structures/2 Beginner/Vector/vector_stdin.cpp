/*
Memory Allocation = malloc

ptr = (int*) malloc(100 * sizeof(int));

Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. 
And, the pointer ptr holds the address of the first byte in the allocated memory.
*/
#include <iostream>
#include <vector>

void vector()
{
    int size;
    std::cout<<"Size of the Vector: ";
    std::cin>>size;
    //std::template <type> Variable_Name
    std::vector <int> Vect;

    for(int i=0; i<size; i++)
    {
        int input;
        std::cout<<"Element "<<i+1<<"\t";
        std::cin>>input;
        Vect.push_back(input);        
    }

    std::cout<<"Elememnts are:\n";

    for(int i=0; i<size; i++)
    {
        std::cout<<"Element "<<i+1<<"\t"<<Vect.operator[](i)<<"\n";
    }
    
    Vect.clear();
}

int main()
{
    vector();
    return 0;
}