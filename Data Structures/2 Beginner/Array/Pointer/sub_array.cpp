#include <iostream>

int *sub_arr(int *arr, int *sub, int low, int high)
{
    int i = low;
    int index = 0;

    while(i<=high)
    {
        sub[index] = arr[i];
        index++;
        i++;
    }

    return sub;
}

void print(int *arr);

int main()
{
    int length = 5;

    int arr[length] = {1,2,3,4,5};
    
    int low=0, high=2;
    
    int *sub = sub_arr(arr, sub, low, high);

    print(sub);

    return 0;
}

void print(int*arr)
{
    int length = sizeof(arr)/sizeof(arr)[0];
    
    for(int i=0; i<=length; i++)
    {
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n";
}