#include<bits/stdc++.h>
using namespace std;
void dividearray(int arr[],int n){
    if(n==1){
        //if array size is 1 no need to devide just print them
        cout << arr[0]<<" ";
        return;
    }
    int leftsize = n/2;
    int rightsize = n - leftsize;
    int left[leftsize],right[rightsize];
    //left array copy
    for (int i=0;i<leftsize;i++){
        left [i]=arr[i];
    }
    //right array copy
    for(int i=0;i<rightsize;i++){
        right[i]=arr[leftsize + i];
    }
    //split both left and right 
    dividearray(left,leftsize);
    dividearray(right,rightsize);
}
int main(){
    int arr[] = { 8,4,2,9 };
    int n =4 ;
    dividearray(arr,n);
    return 0 ;
}
