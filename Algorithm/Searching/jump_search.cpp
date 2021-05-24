#include <iostream>
#include <math.h>

bool JumpSearch(int *arr, int jump, int target, int length, int initial = 0)
{
    if (arr[initial] == target)
    {
        return true;
    }
    
    else if (arr[initial] < target and arr[length-1] >= target)
    {
        initial += jump;
        return JumpSearch(arr, jump, target, length, initial);
    }

    else if (arr[initial] > target and arr[0] <= target)
    {        
        return JumpSearch(arr, jump, target, length, --initial);
    }
    else
    {  
        return false;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};

    int length = 7; //length of array
    int target = 4; //element to be found
    int jump = sqrt(length); //jump to be taken : IDEAL root of the arrary's length

    std::cout<<JumpSearch(arr, jump, target, length);
    return 0;   
}