
//Max Heap

#include<iostream>

using namespace std;

void print(int *arr, int length);

bool ismaxHeap(int *arr, int length)
{
    for(int i=0; i<length-1; i++)
    {
        int parent = i;
        int left_child = 2*parent + 1;
        int right_child = 2*parent + 2;

        if (arr[parent] < arr[left_child] and left_child < length)
        {
            return false;
        }

        if (arr[parent] < arr[right_child] and right_child < length)
        {
            return false;
        }
    }
    return true;
}

void max_heapify(int *arr, int length, int parent)
{
    int left_child = 2*parent + 1;
    int right_child = 2*parent + 2;

    if (arr[parent] < arr[left_child] and left_child < length)
    {
        int temp = arr[parent];
        arr[parent] = arr[left_child];
        arr[left_child] = temp;
    }

    if (arr[parent] < arr[right_child] and right_child < length)
    {
        int temp = arr[parent];
        arr[parent] = arr[right_child];
        arr[right_child] = temp;
    }    
}

int *max_heap(int *arr, int length)
{
    if (ismaxHeap(arr, length) == true)
    {
        return arr;
    }

    for(int i=0; i<length-1; i++)
    {
        max_heapify(arr, length, i);
        //print(arr, length);
    }

    return max_heap(arr, length);
    
}

int main()
{
    int length;    
    cout<<"Length of Array: ";
    cin>>length;

    int arr[length];

    for(int i=0; i<length; i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }

    int *result = max_heap(arr, length);
    //print(arr, length);
    print(result, length);
    
    return 0;
}

void print(int *arr, int length)
{
    for(int i=0; i<length; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}
