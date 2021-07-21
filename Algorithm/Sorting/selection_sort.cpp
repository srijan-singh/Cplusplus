#include <iostream>

void print(int *arr)
{
    for(int i=0; i<=sizeof(arr)+1; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

int min(int *arr ,int low = 0)
{
    int min = 99999;
    int index = low;

    for(int i = low; i<= sizeof(arr)+1; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

int *selection_sort(int *arr)
{
    for(int i=0; i<=sizeof(arr)+1; i++)
    {        
        int smallest = min(arr, i);

        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
    return arr;
}

int main()
{
    int length;
    std::cout<<"Size of Array: ";
    std::cin>>length;
    
    int arr[length];
    std::cout<<"Enter Elements:\n";

    for(int i=0; i<length; i++)
    {
        std::cin>>arr[i];
    }
    
    //int arr[5] = {2,3,4,5,1};

    std::cout<<"Input Array: ";
    print(arr);

    int result = min(arr);
    int *res = selection_sort(arr);

    std::cout<<"Sorted Array: ";
    print(res);

    return 0;
}