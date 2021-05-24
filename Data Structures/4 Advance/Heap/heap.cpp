// C++ program for building Heap from Array 

#include <iostream> 

using namespace std;
int n; // size of array 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. N is size of heap 
void heapify(int arr[], int i) 
{ 
	int smallest = i; // The node which will be heapified 
	int l = 2 * i + 1; // left child node 
	int r = 2 * i + 2; // right child node 

	// Check if left child is smaller than its parent 
	if (l < n && arr[l] < arr[smallest]) 
		smallest = l; 

	// Check if right child is smaller than smallest 
	if (r < n && arr[r] < arr[smallest]) 
		smallest = r; 

	// If smallest is not parent 
	if (smallest != i) { 
		swap(arr[i], arr[smallest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, smallest); 
	} 
} 

// Function to build a Max-Heap from the given array 
void buildHeap(int arr[]) 
{
	// Perform level order traversal 
	// from last non-leaf node and heapify each node 
	for (int i = n; i >= 0; i--) { 
		heapify(arr, i); 
	} 
} 


// Driver Code 
int main() 
{ 
	// Sample array
	int arr[] = { 1, 5, 6, 8, 9, 7, 3}; 

	// calculating size of array
	n = sizeof(arr) / sizeof(arr[0]); 

	cout << "Array representation before buildHeap is: "<<endl; 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " ";

	cout <<endl; 

	// call the buildheap method on the array
	buildHeap(arr); 

  cout << "Array representation after buildHeap is: "<<endl; 

// print the heap
	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 

	

	return 0; 
} 
