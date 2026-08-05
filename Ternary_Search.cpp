#include<bits/stdc++.h>
using namespace std;
int  ternary_search(int arr[],int n,int key){
 int low = 0;
 int high=n-1;
 
 while(low<=high){
     int m1=low + (high-low)/3;
     int m2=high-(high-low)/3;
     if(key==arr[m1]) 
     return m1;
     if(key==arr[m2])
     return m2;
     //searcing between 0 to m1-1
     if(key<arr[m1]){
         high=m1-1;
     }
       //searcing between m2+1 to high 
     else if(key>arr[m2]){
         low=m2+1;
     }
       //searcing between m1+1 to m2-1
     else{
         low = m1+1;
         high=m2-1;
     }
     
 }
 return -1;

}
int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int found = ternary_search(arr,n,key);
    if(found==-1)
    cout<<"key is not in the array.";
    else
    cout<<"key is found at index :"<<found; 
}
