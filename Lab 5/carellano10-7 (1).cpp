#include <iostream>

using namespace std;

class record{  // to store each row using this class. 
  public:
    int key[11]; // for simplicity, we use indices 1-10. 

  record()
  {
    for(int i=1;i<=10;i++)
    key[i] = 0;
  }
};

record* A;
int arraySize;


void countingSort(record* array, int size, int position)
{
    record* B;
    B = new record[arraySize];
    int C[11];


    for(int i = 0; i<11; i++) {
        C[i]= 0;
    }


    for(int j = 0; j<arraySize+1;j++) {
        C[A[j].key[position]]++;
    }


    for(int x = 1; x<11; x++) {
        C[x] = C[x]+C[x-1];
    }


    for(int y = arraySize; y >=0; y--)
    {
        B[C[A[y].key[position]]-1] = array[y];
        C[A[y].key[position]]--;
    }


    for(int i = 0; i<arraySize+1; i++) {
        array[i] = B[i];
    }
    
    
}



void radixSort (record* array, int size) {  
    for(int i = 10; i >=0; i--)
    {
        countingSort(array, size, i);
    }
}


int main(int argc,char **argv) {

  // Get the size of the sequence
  cin >> arraySize;

  A = new record[arraySize+1];

  // Continue reading sequences until there is no more
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
    {
       cin >> A[i].key[j];
    }
  } 

    radixSort(A, arraySize); 
  // Output 
  for(int i=1; i<=arraySize; i++)
      {
    for(int j = 1; j<11;j++)
        cout<<A[i].key[j]<<";";
    cout<<endl;
      }

    // Free allocated space
  delete[] A;

  return 1;
}