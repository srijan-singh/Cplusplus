#include<iostream>

// Print
void print(int *arr, int length);

// To Sort
void insertion_sort(int *arr, int low, int high)
{
    for(int i = high; (i-1)>=low; i--)
    {
        if (arr[i] < arr [i-1])
        {
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
}

int *merge_sort(int* arr, int length, int index = 2)
{
    if (length <= index) // Terminating Condition
    {
        return arr;
    }

    // The range is defined by index.
  
        /*
            If array has 8 elements:  ********
            It will sort array until it's less than length of array.
            1st call  2*1 elements max: ** ** ** ** // Called from Main Function
            2nd call  2*2 elements max: **** ****
            3rd call  2*3 elements max: ********
            Returns Array
        */

        // The range is defined by index.

    for(int i=0; (i+index)<length; i+=index)
    {
        //Sort
        insertion_sort(arr, i, i+index);
    }

    // The range will increase exponentially (i.e. 2,4,8,....i where i<length of array)
    return merge_sort(arr, length, index*2);
}

int main()
{
    int length;    
    std::cout<<"Length of Array: ";
    std::cin>>length;

    int arr[length];

    for(int i=0; i<length; i++)
    {
        std::cout<<"Enter element "<<i+1<<" : ";
        std::cin>>arr[i];
    }

    int *result = merge_sort(arr, length);
    
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