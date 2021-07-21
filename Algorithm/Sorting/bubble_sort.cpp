#include <iostream>

void print(int*arr, int length = 5)
{
    for(int i = 0; i < length; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

int *bubble(int *arr, int length = 5)
{
    int i = 0;

    while (i <= length)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        } 
        i+=1;
    }
    return arr;
}

int *sort(int *arr, int length = 5)
{
    arr = bubble(arr);

    for(int i=0 ; i<length; i++)
    {
        if(arr[i] > arr[i+1])
        {
            sort(arr);
        }
    }
    return arr;
}

int main()
{
    int arr[5] = {3,6,50,2,9};
    print(arr); 
    print(sort(arr));
    return 0;
}