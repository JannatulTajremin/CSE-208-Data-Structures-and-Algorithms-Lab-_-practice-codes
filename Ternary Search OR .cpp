#include<bits/stdc++.h>
using namespace std;
void ternarysearch(int arr[],int n,int key,int &found){
    int low=0,high=n-1;
    while(low<=high){
        int m1=low +(high-low)/3;
        int m2=high-(high-low)/3;
        if(key==arr[m1]){
        found=m1;
        break;
        }
        if(key==arr[m2]){
        found=m2;
        break;
        }
        else if(key<arr[m1])
        high=m1-1;
        else if(key>arr[m2])
        low=m2+1;
        else{
        low=m1+1;
        high=m2-1;}
    }
}
int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int found =-1;
    ternarysearch(arr,n,key,found);
    
    if(found==-1)
    cout<<"key is not in ther arry";
    else
    cout<<"key is at index :"<<found;
}
