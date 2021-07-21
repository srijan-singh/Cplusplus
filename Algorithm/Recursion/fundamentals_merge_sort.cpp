#include <iostream>

using std::endl;
using std::cin;
using std::cout;

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

  int index = 0, left = start, right = mid+1;

  while(left<=mid and right<=end)
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

  while(left<=mid)
  {
    temp[index++] = arr[left++];
  }

  while(right<=end)
  {
    temp[index++] = arr[right++];
  }

  for(int i=start; i<=end; i++)
  {
    arr[i] = temp[i-start];
  }
}

void mergeSort(int arr[], int start, int end)
{
  if (start<end)
  {
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }
}

int main()
{
  int length;
  cout<<"Length of the Array: ";
  cin>>length;

  int arr[length];
  for(int i=0; i<length; i++)
  {
    cout<<"Enter Element "<<(i+1)<<" : ";
    cin>>arr[i];
  }

  cout<<"Given Array: ";
  display(arr, length);

  mergeSort(arr, 0, length-1);

  cout<<"Sorted Array: ";
  display(arr, length);
  return 0;
}