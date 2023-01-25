#include <iostream>
using namespace std;


void extendedBottomUpCutRod(int* p, int n) {
    int* s = new int[n+1];
    
    int* r = new int[n+1];
    r[0] = 0;

    for(int j = 1; j <= n; j++) {

        int negInf = -2147483648;

        for(int i = 1; i <= j; i++) {

            if(negInf < p[i] + r[j - i]) {

                negInf = p[i] + r[j - i];
                s[j] = i;

            }
        }

        r[j] = negInf;

    }

//print
    cout << r[n] << endl;

    while(n > 0) {

        cout<<s[n]<< " ";
        n = n - s[n];


    }

    cout<<"-1"<<endl;


}

int main(int argc,char **argv) {
    int size;
    cin >> size;

    int* p;
    p =new int [size+1];
    p[0] = 0;


    for(int i=1; i<=size; i++){

        cin >> p[i];

    }



    extendedBottomUpCutRod(p,size);
    

}