/*
Memory Allocation = malloc

ptr = (int*) malloc(100 * sizeof(int));

Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. 
And, the pointer ptr holds the address of the first byte in the allocated memory.
*/
#include <iostream>

void dynamic_array()
{
    int len_arr;
    int *d_arr;

    std::cout<<"Memory Allocated using malloc()\n";
    std::cout<<"Number of elements: ";
    std::cin>>len_arr;
    
    d_arr = (int*)malloc(len_arr*sizeof(int));

    for (int i=0; i<len_arr; i++)
    {
        std::cout<<"Element "<<i+1 <<"\t";
        std::cin>>d_arr[i];
    }
    std::cout<<"\nElements are:\n";
    for(int i=0; i<len_arr; i++)
    {
        std::cout<<"Element "<<i+1 <<"\t"<<d_arr[i]<<"\n";
    }
    free(d_arr);
}

int main()
{
    dynamic_array();
    return 0;
}