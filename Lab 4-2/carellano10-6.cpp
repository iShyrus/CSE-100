#include <iostream>
#include <stdlib.h>
#include <limits>
#include <algorithm>
using namespace std;


int partition(int arr[], int p, int r){
    int x = arr [r];
    int i = p-1;
    
        for(int j = p; j <= r-1; j++ ){
            
            if(arr[j] <= x){
                i++;
                swap(arr[i], arr[j]);
                
            }
        }
        
        swap(arr[i+1],arr[r]);
        return i+1;
}

int randomPartition(int arr[], int p, int r){
    int random = p + rand() % (r - p+1);
    swap(arr[random],arr[r]);
    return partition(arr, p, r);
}

void randomQuickS(int arr[], int p, int r){
    if(p < r){
        int q;
        q = randomPartition(arr, p, r);
        randomQuickS(arr,p, q-1);
        randomQuickS(arr,q+1,r);
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

   randomQuickS(numElements, 0, arraysize-1);

for(int i =0; i<arraysize; i++){
    cout<<numElements[i]<<";";
}

}



