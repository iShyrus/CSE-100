#include <iostream>
using namespace std;

void Merge(int array[],int first, int mid, int last){
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int L[n1+1];
    int R[n2+1];

    for(int i = 1; i <= n1; i++){
        L[i] = array[first+i-1];
    }
    for(int j = 1; j<=n2; j++){
        R[j] = array[mid+j];
    }
    int inf = 2147483647;
    L[n1+1] = inf;
    R[n2+1] = inf;
    int i = 1;
    int j = 1;

    for(int k = first; k<=last; k++){
        if (L[i]<= R[j]){
            array[k]=L[i];
            i=i+1;
        }
        else{
            array[k] = R[j];
            j = j + 1;
        }
        
    }

}

void mergeSort(int array[],int first, int last){
if(first<last){
    int mid = (last+first) * .5;
    mergeSort(array, first, mid);
    mergeSort(array, mid+1, last);
    Merge(array,first, mid, last);

}
}

int main(int argc,char **argv) {

    int *numElements;
    int element;
    int arraySize;
    int j;
    int holder;

    cin >> arraySize;
    numElements = new int[arraySize];


    for(int i=0;i<arraySize;i++){
        cin>>element;
        numElements[i] = element;
    }

mergeSort(numElements,0, arraySize);
for(int i =0; i<arraySize; i++){
    cout<<numElements[i+1]<<";";
}

}
