#include<bits/stdc++.h>
using namespace std;
long long comparisonCount = 0;
int partition(int a[],int low,int high){
    int pivot=low;
    int i=low+1;
    int j=high;
    while(i<=j){
while(i <= j)
        {
            comparisonCount++;

            if(a[i] <= a[high])
                i++;
            else
                break;
        }
  while(j >= i)
        {
            comparisonCount++;

            if(a[j] > a[high])
                j--;
            else
                break;
        }
        if(i<j)
        swap(a[i],a[j]);
    }
    swap(a[j],a[pivot]);
    return j;
}
void quicksort(int a[],int low,int high){
    if(low<high){
    int p = partition(a,low,high);
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
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
 cout << "\nNumber of comparisons: "
         << comparisonCount << endl;

}
