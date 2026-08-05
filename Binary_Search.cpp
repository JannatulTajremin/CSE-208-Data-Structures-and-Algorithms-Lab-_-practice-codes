#include<bits/stdc++.h>
using namespace std;
void binary_search(int arr[],int n,int key,int &found){
 int low = 0;
 int high=n-1;
 
 while(low<=high){
     int mid=(low+high)/2;
     if(key==arr[mid]){
         found = mid;
         break;
     }
     else if(key<arr[mid]){
         high =mid-1;
     }
     else  if(key>arr[mid]){
         low = mid+1;
     }
     
 }

}
int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int found = -1;
    
    binary_search(arr,n,key,found);
    if(found==-1)
    cout<<"key is not in the array.";
    else
    cout<<"key is found at index :"<<found; 
}
