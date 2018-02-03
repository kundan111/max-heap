//heap-increase key
//date: 03-02-2018

#include <iostream>
#include <assert.h>
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
int main(){
	
    int heap_size;
    cin >> heap_size;
    
    int arr[heap_size];
    
    for(int i = 0 ; i < heap_size ; i++){
        cin >> arr[i];
    }
    
    build_max_heap(arr , heap_size);
   
    int pos , key;
    cin >> pos >> key;
    assert(pos<= heap_size-1);
	if(increase_key(arr , pos , key)==-1){
    	cout << "Error! value should be greater than previous value.";
	}
	else{
		for(int i = 0 ; i < heap_size ; i++)
           cout << arr[i] << " ";	
	}
     return 0;


}
  

