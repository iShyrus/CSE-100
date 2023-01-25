#include <iostream>
using namespace std;
#include <limits.h>

void printOptimalParens(int s,int i, int j,  int *a)
{
    if (i == j){
        cout <<"A"<<(i-1);
        return;

    }
    else{
        cout << "(";
        printOptimalParens(s,i, *((a+i*s)+j), a);    
        printOptimalParens(s,*((a+i*s)+j) + 1, j,  a);
        cout << ")";

   }
   
}




void matrixChainOrder(int p[], int n){
    int s[n][n];
    int m[n][n];
    
    for (int i=1; i<n; i++){
        m[i][i] = 0;
    }
    
    for (int c=2; c<n; c++){
        for (int i=1; i<n-c+1; i++){
            int j = i+c-1;
            m[i][j] = INT_MAX; 

            for (int k=i; k<=j-1; k++){
                int q = m[i][k] + m[k+1][j] + ((p[i-1]) * (p[k])* (p[j]));
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }


        }
    }
    cout << m[1][n-1];
    cout << endl;
    printOptimalParens(n,1, n-1,  (int *)s);
    cout<<endl;
}


int main(){
    int size;
    cin >> size;
    int * a = new int[size];

    for (int i=0; i<=size; i++){

        cin >> a[i];

    }
    matrixChainOrder(a, size+1);
    
}