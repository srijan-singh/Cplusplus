/*
Contiguous Allocation = calloc

ptr = (float*) calloc(25, sizeof(float));

This statement allocates contiguous space in memory for 25 elements 
each with the size of the float.
*/
#include <iostream>

void dynamic_array()
{
    int len_arr;
    int *d_arr;

    std::cout<<"Memory Allocated using calloc()\n";
    std::cout<<"Number of elements: ";
    std::cin>>len_arr;
    
    d_arr = (int*)calloc(len_arr,sizeof(int));

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