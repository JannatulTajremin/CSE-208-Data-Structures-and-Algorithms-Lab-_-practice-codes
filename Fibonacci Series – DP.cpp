#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long>dp;
long long fibonacci(int n){
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else if(dp[n]==0){
        dp[n]=fibonacci(n-1)+fibonacci(n-2);
        return dp[n];
    }
   return dp[n]; 
}
int main(){
    cin>>n;
    dp.assign(n+1,0);
    long long result = fibonacci(n);
    cout<<result;
}
