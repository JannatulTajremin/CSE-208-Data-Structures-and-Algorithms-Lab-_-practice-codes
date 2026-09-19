#include<bits/stdc++.h>
using namespace std;
int LCS (int A[],int B[],int i,int j,int N,int M){
if(i==N||j==M)
    return 0;
else if(A[i]==B[j])
    return 1+LCS(A,B,i+1,j+1, N, M);
else
    return max(LCS(A,B,i+1,j,N,M),LCS(A,B,i,j+1,N,M));
}
int main(){
int N;
cin>>N;
int  A[N];
for(int i=0;i<N;i++){
    cin>>A[i];
}
int M;
cin>>M;
int B[M];
for(int i=0;i<M;i++){
cin>>B[i];
}
int result = LCS(A,B,0,0,N,M);
cout<<result;
}
