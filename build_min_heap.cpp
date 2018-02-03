//build min-heap
//coded by: kundan111
//date: 01-02-18
//time-complexity: O(n)
//space complexity: O(logn)

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void min_heapify(int *A , int i , int heap_size)
{
    int l = 2*i+1;
    int r = 2*i + 2;
    int minimum;
    
    if(l<heap_size && A[l] < A[i])
        minimum = l;
    else
        minimum = i;
    if(r<heap_size && A[r] < A[minimum])
        minimum = r;
    if(minimum!=i)
    {
	
       swap(A[i],A[minimum]);
       min_heapify(A , minimum, heap_size);
   }
}

void build_min_heap(int *A , int heap_size){
    
    for(int i = heap_size/2 ; i >= 0 ; i--)
        min_heapify(A , i ,  heap_size);
}

int main()
{
    int heap_size;
    cin >> heap_size;
    
    int arr[heap_size];
    
    for(int i = 0 ; i < heap_size ; i++){
        cin >> arr[i];
    }
    
    build_min_heap(arr , heap_size);
    
    for(int i = 0 ; i < heap_size ; i++){
        cout << arr[i] << " ";
    }
    
    
    return 0;
}
