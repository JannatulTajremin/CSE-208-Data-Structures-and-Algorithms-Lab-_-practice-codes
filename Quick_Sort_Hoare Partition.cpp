#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    // pivot = 1st index of array
   int pivot = low;
   //too_big = 2nd index of array
   int too_big = low+1;
   //too_small = last index of array
   int too_small=high;
   //loop will comtinue untill too_big is  greater than too_small
   while(too_big<=too_small){
       while(too_big<=high && arr[too_big]<=arr[pivot]){
           ++too_big;
       }
       while(too_small>=low && arr[too_small]>arr[pivot]){
           --too_small;
       }
       if(too_big<too_small){
           swap(arr[too_big],arr[too_small]);
       }
   }
   swap(arr[too_small],arr[pivot]);
   return too_small;
}
void quicksort(int arr[],int low,int high){
    //checking for 0 to n-1 
    if(low<high){
        // p = pivot's correct position
        int p = partition(arr,low,high);
        //quicksort for left part
        quicksort(arr,low,p-1);
        //quicksort for right sort
        quicksort(arr,p+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    //calling quicksort function passing values of low = 0 and high = n-1
    quicksort(arr,0,n-1);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
