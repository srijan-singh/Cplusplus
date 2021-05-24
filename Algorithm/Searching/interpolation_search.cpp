/*
// The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[hi]. And
// smaller value when closer to arr[lo]
pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]
*/
#include <iostream>

bool InterpolationSearch(int *arr, int target, int high, int low=0)
{
    if (target <= arr[high])
    {
        int pos = low + ( (target - arr[low])*(high - low) / (arr[high] - arr[low]) );

        if (arr[pos] == target)
        {
            return true;
        }

        else if (arr[target] > target)
        {
            return InterpolationSearch(arr, target, pos, low);
        }

        else if (arr[target] < target)
        {
            return InterpolationSearch(arr, target, low, pos);
        }

        return false;
    }  
    
    return false;
}

int main()
{
    int arr[7] = {1,3,5,7,9,11,13}; // Sorted array with ***Uniform Progression***
    
    int length = 7; //length of array
    int target = 13; //element to be found

    std::cout<<InterpolationSearch(arr, target, length-1);
    return 0;   
}