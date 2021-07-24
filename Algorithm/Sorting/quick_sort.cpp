#include <iostream>

using std::endl;
using std::cin;
using std::cout;

void display(int arr[], int length, int low=0)
{
  for(int i=low; i<length; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void swap(int *num1, int *num2)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int partition(int arr[], int start, int end)
{
  int pivot = arr[end];

  int initial = start-1;

  for (int i=start; i<=end-1; i++)
  {
    if(arr[i] < pivot)
    {
      swap(&arr[++initial], &arr[i]);
    }
  }

  //Position Pivot
  swap(&arr[++initial], &arr[end]);

  return initial;
}

void quickSort(int arr[], int start, int end)
{
  if(start<end)
  {
    int pivot_index = partition(arr, start, end);
    quickSort(arr, start, --pivot_index);
    quickSort(arr, ++pivot_index, end);
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

  quickSort(arr, 0, length-1);

  cout<<"Sorted Array: ";
  display(arr, length);
  return 0;
}