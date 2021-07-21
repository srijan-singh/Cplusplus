#include<iostream>

void print(int *, int);

bool isSorted(int *arr, int high, int low=0)
{
    for(int i=low; (i+1)<high; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}

void pivotPositioning(int *arr, int high, int low)
{
    for(int i=low; (i+1)<high; i++)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

void quickSort(int *arr, int length, int pivot) 
{
    pivotPositioning(arr, pivot+1, 0);
    //print(arr, length);
    pivotPositioning(arr, length, pivot);
    //print(arr, length);
}

int *quickSort(int *arr, int length)
{
    int pivot = length/2;

    quickSort(arr, length, pivot);

    if (isSorted(arr, length) == false)
    {
        while (pivot > 0)
        {
            pivot--;
            quickSort(arr, length, pivot);
        }   

        while (pivot<length)
        {
            pivot++;
            quickSort(arr, length, pivot);
        }
        
    }

    return arr;
}

int main()
{
    int length ;
    std::cout<<"Enter length of the array: ";
    std::cin>>length;

    int arr[length] ;
    for(int i=0; i<length; i++)
    {
        std::cout<<"Enter Element "<<(i+1)<<" : ";
        std::cin>>arr[i];
    }

    quickSort(arr, length);

    print(arr, length);

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