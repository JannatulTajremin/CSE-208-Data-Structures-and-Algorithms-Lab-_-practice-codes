#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i]; //arr[n] input 
    int m=n/2;
    
    int arr1[m] ,arr2[m];
    
    /*for(int i=0,j=0;i<m&&j<m;i++,j++)
    arr1[j]=arr[i];*/
    for(int i=0;i<m;i++)
    arr1[j]=arr[i]; //arr1[m] input
    
    for(int i=m,k=0;i<n&&k<m;i++,k++)
    arr2[k]=arr[i]; //arr2[m] input
    
    for(int i=0;i<m;i++)
    cout<<arr1[i]<<" "; //arr1[m] print 
    cout<<endl;
    
    for(int i=0;i<m;i++)
    cout<<arr2[i]<<" "; //arr2[m] print 
    
}
