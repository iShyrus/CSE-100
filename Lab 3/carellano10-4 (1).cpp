#include <iostream>
using namespace std;





int maxCrossingSum(int arr[], int low, int mid, int high)
{
int sum = 0;
int leftsum = -2147483648;
for (int i = mid; i >= low; i--)
{
sum = sum + arr[i];
if (sum > leftsum)
leftsum = sum;
}
int rightsum = -2147483648;
sum = 0;
for (int i = mid+1; i <= high; i++)
{
sum = sum + arr[i];
if (sum > rightsum)
rightsum = sum;
}

return leftsum + rightsum;
}





int maxSubArraySum(int arr[], int low, int high)
{
if (low == high){
    return arr[low];
}

else{
int mid = (low + high)/2;

int leftsum = maxSubArraySum(arr, low, mid);
int rightsum = maxSubArraySum(arr, mid+1, high);
int crosssum = maxCrossingSum(arr, low, mid, high);
if(leftsum >= rightsum && leftsum>= crosssum){
    return leftsum;
    
}
if(rightsum >= leftsum && rightsum >= crosssum){
    return rightsum;

}
else{
    return crosssum;
}
}

}



int main()
{

        int *numElements;
    int element;
    int arraySize;
    int holder;

    cin >> arraySize;
    numElements = new int[arraySize];


    for(int i=0;i<arraySize;i++){
        cin>>element;
        numElements[i] = element;
    }





int max_sum = maxSubArraySum(numElements, 0, arraySize-1);
cout<<max_sum;;

}