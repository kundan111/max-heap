//delete key from the heap given the key position
//date: 03-02-2018

#include <iostream>
#include<climits>
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

int increase_key(int *A , int i , int key){
    if(key < A[i]){
		return -1;
	}
    A[i] = key;
    while(i > 0 && A[(i-1)/2] < A[i]){
        swap(A[(i-1)/2] , A[i]);
        i = (i-1)/2;
    }
    return 1;
}

int heap_extract_max(int *A , int heap_size){
    if(heap_size<1)
        cout << "Heap underflow!!" << endl;
    int max = A[0];
    A[0] = A[heap_size - 1];
    heap_size = heap_size - 1;
    max_heapify(A , 0 , heap_size);
    return max;
    
}
int main(){
	
    int heap_size;
    cin >> heap_size;
    
    int arr[heap_size];
    
    for(int i = 0 ; i < heap_size ; i++){
        cin >> arr[i];
    }
    
    build_max_heap(arr , heap_size);
    
    int posn_of_key_to_be_deleted;
    cin >> posn_of_key_to_be_deleted;
    
    increase_key(arr , posn_of_key_to_be_deleted , INT_MAX);
    
    heap_extract_max(arr , heap_size);
    
    for(int i = 0 ; i < heap_size-1 ; i++)
           cout << arr[i] << " ";
     
     return 0;


}
  

