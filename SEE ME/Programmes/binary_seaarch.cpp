//
// Created by Srijanverse on 22-10-2020.
//
#include <iostream>

int binary_search(int arr[], int high, int low, int mid, int x)
{
    if(x == arr[mid])
    {
        std::cout<<"Found at index: "<<mid;
    }
    else if(x > arr[mid])
    {
        binary_search(arr, high, mid, (high + mid)/2, x);
    }
    else if(x < arr[mid])
    {
        binary_search(arr, mid, low, (low + mid)/2, x);
    }
    else
    {
        std::cout<<"Element not present in the list!";
    }
    return 0;
}

int main() {
    int arr[100] = {1, 3, 5, 12, 23, 34};
    std::cout<<"{ ";
    for (int i =0; i<5; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"}";
    int high = 5;
    int low = 0;
    int mid = (high + low)/2;
    int x = 12;
    std::cout<<"\nElement to be found: "<<x<<"\n";

    binary_search(arr, high, low, mid, x);

    return 0;
}


