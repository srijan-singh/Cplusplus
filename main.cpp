#include<iostream>

using namespace std;

int *insertion_sort(int *arr, int high)
{
    for(int i=high; i>0; i--)
    {
        if (arr[i] < arr[i-1])
        {
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
    return arr;
}

int *sort(int *arr, int low, int high)
{
    for(int i=low; i<high; i++)
    {
        if(arr[i+1] < arr[i])
        {
            arr = insertion_sort(arr,i+1);
        }
    }    
    return arr;
}

int *merge_sort(int *arr, int length, int index=2)
{
    if (length <= index) // Terminating Condition
    {
        return arr;
    }

    //The Sorting Starts from leaf node.
    
    for(int i=0; (i+index)<=length; i+=index) // Merging and Sorting
    {
        sort(arr, i, i+index);
    }

    return merge_sort(arr, length, index*2);
}

void print(int *arr, int length);

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

    int *result = merge_sort(arr, length);
    
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
