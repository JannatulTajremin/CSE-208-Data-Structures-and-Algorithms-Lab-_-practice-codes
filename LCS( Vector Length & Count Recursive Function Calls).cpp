#include<bits/stdc++.h>
using namespace std;
long long callcount = 0;

int LCS(vector<int>&A,vector<int>&B,int i,int j){
    callcount++;
    if(i==(int)A.size()||j==(int)B.size())
    return 0;
    else  if (A[i]==B[j])
    return 1+LCS(A,B,i+1,j+1);
    else 
    return max(LCS(A,B,i+1,j),
               LCS(A,B,i,j+1));
}

int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    int M;
    cin>>M;
    vector<int>B(M);
    for(int i=0;i<M;i++) cin>>B[i];
    
    int result =LCS(A,B,0,0);
    cout<<"LCS using Naive Recursive Approach:"<<result<<endl;
    cout<<"Number of Recursive Function Calls:"<<callcount;
}
