#include<bits/stdc++.h>
using namespace std;
long long comparisons = 0;
void merge(int a[],int left[],int right[],int n,int l,int r){
    int i=0,j=0,k=0;
    while(i<l && j<r){ 
        comparisons ++;
        if(left[i]<right[j]){
        a[k]=left[i];
        i++;
        }
        else{
        a[k]=right[j];
        j++;
        }
        k++;
    }
    while(i<l){
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<r){
        a[k]=right[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int n){
    if(n<=1)
    return; 
    int l=n/2;
    int r=n-l;
    int left[l],right[r];
    for(int i=0;i<l;i++)
    left[i]=a[i];
    for(int i=0;i<r;i++)
    right[i]=a[i+l];
    mergesort(left,l);
    mergesort(right,r);
    merge(a,left,right,n,l,r);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    cin>>a[i];
    mergesort(a,n);
    for (int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"comparisons : "<<comparisons;
}
