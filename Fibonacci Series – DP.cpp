#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long>dp;
long long factorial(int n){
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else if(dp[n]==0){
    return factorial(n-1)+factorial(n-2);    
    }
   return dp[n]; 
}
int main(){
    cin>>n;
    dp.assign(n+1,0);
    long long result= factorial(n);
    cout<<result;
}
