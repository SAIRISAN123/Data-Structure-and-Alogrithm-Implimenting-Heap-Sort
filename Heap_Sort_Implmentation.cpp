#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    //build heapify
    int largest = root; // at begining take largest value as root
    int left = 2*root + 1; // assigning left = 2*i + 1
    int right = 2*root + 2; // assigning right = 2*i + 2
 
    
    if (left < n && arr[left] > arr[largest])  // If left child > root....
        largest = left;
 
    // If right child > largest........
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not equal to root
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
 
        // Recursively heapify....
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    // building  heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    // extracting elements from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move root to end..
        swap(arr[0], arr[i]);
 
        //implement heapify
        heapify(arr, i, 0);
    }
}


void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " "; //this prints elements of array
    cout << "\n";
}

// main program
int main()
{   
    cout<<"200552V"<<endl;
    int heap_arr[] = {4,17,3,12,9,6};
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
    
}
