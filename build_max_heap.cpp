//build max-heap
//coded by: kundan111
//date: 01-02-18
//time-complexity: O(n)
//space complexity: O(logn)

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void max_heapify(int *A , int i , int heap_size)
{
    int l = 2*i+1;
    int r = 2*i + 2;
    int largest;
    
    if(l<heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if(r<heap_size && A[r] > A[largest])
        largest = r;
    if(largest!=i)
    {
	
       swap(A[i],A[largest]);
       max_heapify(A , largest, heap_size);
   }
}

void build_max_heap(int *A , int heap_size){
    
    for(int i = heap_size/2 ; i >= 0 ; i--)
        max_heapify(A , i ,  heap_size);
}

int main()
{
    int heap_size;
    cin >> heap_size;
    
    int arr[heap_size];
    
    for(int i = 0 ; i < heap_size ; i++){
        cin >> arr[i];
    }
    
    build_max_heap(arr , heap_size);
    
    for(int i = 0 ; i < heap_size ; i++){
        cout << arr[i] << " ";
    }
    
    
    return 0;
}
