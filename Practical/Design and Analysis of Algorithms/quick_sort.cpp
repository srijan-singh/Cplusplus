#include <iostream>

void print(int *arr, int length);

void quick_arrangement(int *arr, int pivot)
{
    for(int i = pivot - 1; i>=0 ; i--)
    {
        
        // If pivot element is less than element at left then swap
        if (arr[pivot] < arr [i])
        {
            int temp = arr[pivot];
            arr[pivot] = arr[i];
            arr[i] = temp; 
        }
    }
}

int *quick_sort(int *arr, int length)
{
    if (length-1 == 0) //Terminating Condition (pivot = 0)
    {
        return arr;
    }

    // Pivot 
    int pivot = length - 1; // Last element
    
    // Arranging array with respect to pivot
    quick_arrangement(arr, pivot);

    // Changing the range and pivot by recurssion
    return quick_sort(arr, length-1);    
}

int main()
{
    int length;
    std::cout<<"Enter the length of the array: ";
    std::cin>>length;

    int arr[length];

    for(int i=0; i<length; i++)
    {
        std::cout<<"Enter element "<<(i+1)<<" : ";
        std::cin>>arr[i];
    }

    int *result = quick_sort(arr, length);

    print(result, length);

    return 0;
}

void print(int *arr, int length)
{
    std::cout<<"Sorted Array: ";
    for(int i=0; i<length; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}