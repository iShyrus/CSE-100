#include <iostream>
using namespace std;


void maxHeap(int array[], int i, int size)
{
    int r = 2 * i + 1;
    int largest;
    int l = 2 * i ;

    if((l < size) && (array[l] > array[i]))
    
        largest = l;
        
    else
    
        largest = i;
        
        
    if((r < size) && (array[r] > array[largest]))
    
    
        largest = r;
        
        
        
    if(largest != i)
    {
        swap(array[i], array[largest]);
        maxHeap(array, largest, size);
    }
}






void buildMaxHeap(int array[], int heapSize)
{
    for(int i = (heapSize / 2); i >= 0; i--)
    {
        maxHeap(array, i, heapSize);
    }
}




void heapSort(int array[], int heapSize)
{
    
    buildMaxHeap(array, heapSize);
    
    for(int i = heapSize - 1 ; i >=1; i--)
    {
        
        swap(array[0], array[i]);
        heapSize--;
        maxHeap(array, 0, heapSize);
        
    }
}



int main(int argc,char **argv) {

    int *numElements;
    int element;
    int arraysize;
    int holder;

    cin >> arraysize;
    numElements = new int[arraysize];


    for(int i=0;i<arraysize;i++){
        cin>>element;
        numElements[i] = element;
    }

heapSort(numElements, arraysize);
for(int i =0; i<arraysize; i++){
    cout<<numElements[i]<<";";
}

}