#include<bits/stdc++.h>
using namespace std;
int LCS(string A,string B,int i,int j){
    if(i==A.size()||j==B.size()){
        return 0;
    }
    else if(A[i]==B[j]){
        return 1+LCS(A,B,i+1,j+1);
    }
    else
    return max(LCS(A,B,i+1,j),LCS(A,B,i,j+1));
}
int main(){
    string A,B;
    cin>>A>>B;
    int result = LCS(A,B,0,0);
    cout<<result;
}
