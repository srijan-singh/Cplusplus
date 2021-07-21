#include <iostream>

using std::cout;
using std::endl;

void display(int arr[], int length)
{
    for(int i=0; i<length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void merge(int arr[], int start, int mid, int end)
{
    int length = end - start + 1;

    int temp[length];

    int left = start, right = mid+1, index = 0;

    while (left <= mid and right<= end)
    {
        if(arr[left] <= arr[right])
        {
            temp[index++] = arr[left++];
        }
        else
        {
            temp[index++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[index++] = arr[left++];
    }

    while (right <= end)
    {
        temp[index++] = arr[right++];
    }

    for(int i=start; i<=end; i++)
    {
        arr[i] = temp[i - start];
    }
    
    
    
}


void mergeSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}


int main() 
{
    int size = 6; 
    int arr[size] = {6, 5, -12, 10, -9, 1};
  //int size = sizeof(arr) / sizeof(arr[0]);
  
    printf("Original array\n");
    display(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array\n");
    display(arr, size);
}
