#include <iostream>
using namespace std;


int main() {
    int* numElements;
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


    for(int i=0;i<arraySize;i++){

    holder = numElements[i];
    j = i-1;
        while (holder <numElements[j] &&j>=0){

            numElements[j+1] = numElements[j];
            j = j-1;
            
        }
    numElements[j+1] = holder;


    if (i>=1){
    for(int k = 0;k <= i;k++){
        cout<<numElements[k]<<";";
    }
    cout<<"\n";
    }

    }




    return 0;
}