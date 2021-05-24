#include<iostream>

int arr_sum(int *arr, int size)
{
    int sum = 0;
    for(int i=0; i<size; i++)
    {
        sum+= arr[i];
    }
    return sum;
}

void pointer_as_argmnt()
{
    int arr[5] = {1, 2, 4, 3, 5};
    
    std::cout<<arr_sum(arr, 5);    

}

int main()
{
    pointer_as_argmnt();
}