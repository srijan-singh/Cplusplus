#include <iostream>

void dynamic_array()
{
    int len_arr;
    int *d_arr;
    std::cout<<"Number of elements: ";
    std::cin>>len_arr;
    d_arr = new int[len_arr];

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
}

int main()
{
    dynamic_array();
    return 0;
}