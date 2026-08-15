#include<bits/stdc++.h>
using namespace std;

int swapCount = 0;   // total swap count

int partition(int a[], int low, int high){
    int pivot = low;
    int i = low + 1;
    int j = high;

    while(i <= j){

        while(i <= high && a[i] <= a[pivot])
            i++;

        while(j > low && a[j] > a[pivot])
            j--;

        if(i < j){
            swap(a[i], a[j]);
            swapCount++;       // swap count
        }
    }

    swap(a[j], a[pivot]);
    swapCount++;               // swap count

    return j;
}

void quicksort(int a[], int low, int high){
    if(low < high){
        int p = partition(a, low, high);

        quicksort(a, low, p-1);
        quicksort(a, p+1, high);
    }
}

int main(){
    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];

    quicksort(a, 0, n-1);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";

    cout << "\nTotal swaps = " << swapCount << endl;
}
