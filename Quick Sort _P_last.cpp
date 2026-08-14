#include<bits/stdc++.h>
using namespace std;
int partition (int a[],int low,int high){
    int pivot = high;
    int i=low;
    int j=high - 1;
    while(i<=j){
        while(i<=j && a[i]<=a[pivot])
        i++;
        while(j>=i && a[j]>a[pivot])
        j--;
        if(i<j)
        swap(a[i],a[j]);
    }
    swap(a[i],a[pivot]);
    return i ;
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
