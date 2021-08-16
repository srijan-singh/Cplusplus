#include <iostream>

int peak_finder(int *arr, int high, int low=0)
{
    int mid = (high+low)/2;

    if(arr[mid] >= arr[mid+1] and arr[mid] >= arr[mid+1])
    {
        return arr[mid];
    }

    else if (arr[mid] < arr[mid-1])
    {
        return peak_finder(arr, mid, 0);
    }

    return peak_finder(arr, high, mid);
    
}

int main()
{
    int length = 9;
    int arr[length] = {4,2,-1,3,7,9,10,1,0};
    std::cout<<peak_finder(arr, length);
    return 0;
}