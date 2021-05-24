#include <iostream>

int binary_search(int *arr, int target, int high=0, int low=0, int mid=0)
{
  if (high == low)
  {
    high = sizeof(arr);
  
    return binary_search(arr, target, high);
  }
  else
  {
    mid = (high+low)/2;

    if(target >= low and target <= high)
    {
      if (target == arr[mid])
      {
        return true;
      }
      else if (target < arr[mid])
      {
        return binary_search(arr, target, mid, low, (mid+low)/2);
      }
      else if (target > arr[mid])
      {
        return binary_search(arr, target, high, mid, (high+mid)/2);
      }      
    }
  }
  return false;
      
}
int main()
{
  int arr[5] = {1, 2, 3, 4, 5};

  std::cout<<binary_search(arr, 2);
}