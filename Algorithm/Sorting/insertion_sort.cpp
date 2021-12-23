//Insertion Sort
#include <iostream>

void print(int *arr, int length)
{
    for(int i=0; i<length; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

int *insertion_sort(int *arr, int high)
{
    for(int i=high; i>0; i--)
    {
        if (arr[i] < arr[i-1])
        {
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
    return arr;
}

int *insertion_sort(int *arr)
{
    for(int i=0; i<sizeof(arr); i++)
    {
        if(arr[i+1] < arr[i])
        {
            arr = insertion_sort(arr,i+1);
        }
    }
    
    return arr;
}


int main()
{
    int length;
    std::cout<<"Length of Array: ";
    std::cin>>length;
    std::cout<<"Enter Elements:\n";
    int arr[length];
    for(int i=0; i<length; i++)
    {
        std::cin>>arr[i];
    }
    print(insertion_sort(arr),length);
    return 0;
}