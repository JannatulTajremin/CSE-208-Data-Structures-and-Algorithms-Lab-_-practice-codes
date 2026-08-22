#include<bits/stdc++.h>
using namespace std ;
void merge(int left[],int right[],int leftsize,int rightsize,int arr[],int n){
    int i=0,j=0,k=0;
    while(i<leftsize&&j<rightsize){
        if(left[i]<=right[j]){
            
            //for descending order sorting 
            //if(left[i]>=right[j])
            
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<leftsize){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<rightsize){
        arr[k]=right[j];
        j++;
        k++;
    }
}
void dividearray(int arr[],int n){
    // set base case = 1
    //n<1 means n==0 for empty array
    if(n <= 1)
    return;
    // size of left & right array
    int leftsize =n/2;
    int rightsize = n- leftsize;
    //copy values of arr[] into left[] array
    int left[leftsize],right[rightsize];
    for (int i=0;i<leftsize;i++){
        left[i]=arr[i];
    }
    //copy rest values of arr[] into right[]array
    for (int i=0;i<rightsize;i++){
        right[i]=arr[i+leftsize];
    }
    //divide left & right array until arraysize n==1
   dividearray(left,leftsize);
   dividearray(right,rightsize);
   //calling merge() function for merging divided array
   merge(left,right,leftsize,rightsize,arr,n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    //array arr[] input
    for (int i=0;i<n;i++)
    cin>>arr[i];
    //calling dividearray() function for making each element into a single array
    dividearray(arr,n);
    //printing sorted array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //time complexity :O(nlogn)
}
