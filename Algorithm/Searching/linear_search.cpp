#include <iostream>

bool LinearSearch(int *arr, int target, int length, int initial=0)
{
    if (initial < length)
    {
        if (arr[initial] == target)
        {
            return true;
        }
        return LinearSearch(arr, target, length, ++initial);        
    }
    return false;
}

int main()
{
    int arr[7] = {1,7,2,5,3,6,4};
    
    int length = 7; //length of array
    int target = 7; //element to be found

    std::cout<<LinearSearch(arr, target, length);
    return 0;   
}