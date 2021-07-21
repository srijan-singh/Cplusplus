#include<iostream>

using namespace std;

void print(int *arr, int length);

bool isminHeap(int *arr, int length) // To verify
{
    for(int i=0; i<length-1; i++)
    {
        int parent = i;
        int left_child = 2*parent + 1;
        int right_child = 2*parent + 2;
        
        // Return false if parent is greater than child  
      
        if (arr[parent] > arr[left_child] and left_child < length)
        {
            return false;
        }

        if (arr[parent] > arr[right_child] and right_child < length)
        {
            return false;
        }
    }
    return true;
}

void min_heapify(int *arr, int length, int parent)
{
    int left_child = 2*parent + 1;
    int right_child = 2*parent + 2;

    // Swap if parent is greater than child
  
    if (arr[parent] > arr[left_child] and left_child < length)
    {
        int temp = arr[parent];
        arr[parent] = arr[left_child];
        arr[left_child] = temp;
    }

    if (arr[parent] > arr[right_child] and right_child < length)
    {
        int temp = arr[parent];
        arr[parent] = arr[right_child];
        arr[right_child] = temp;
    }    
}

int *min_heap(int *arr, int length)
{
    if (isminHeap(arr, length) == true) // Terminating Condition 
    {
        return arr; // If min heap will return the array
    }

    for(int i=0; i<length-1; i++)
    {
        min_heapify(arr, length, i); // Heapifying from root node till leaf node
    }

    return min_heap(arr, length); // Recusrion till it's min heap
    
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

    int *result = min_heap(arr, length);
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