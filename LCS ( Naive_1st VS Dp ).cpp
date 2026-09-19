#include<bits/stdc++.h>
using namespace std;

long long recCalls = 0;
long long dpCells = 0;

int naiveLCS(vector<int>&A, vector<int>&B, int i, int j){
    recCalls++;
    if(i==(int)A.size() || j==(int)B.size())
    return 0;
    else if(A[i] == B[j])
    return 1 + naiveLCS(A, B, i+1, j+1);
    else    
    return max(naiveLCS(A, B, i+1, j),
               naiveLCS(A, B, i, j+1));
}

int dpLCS(vector<int>&A, vector<int>&B){
    int m = A.size(), n = B.size();
    vector<vector<int>> C(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            dpCells++;
            if(A[i-1] == B[j-1])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = max(C[i-1][j], C[i][j-1]);
        }
    }
    return C[m][n];
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int M;
    cin >> M;
    vector<int> B(M);
    for(int i=0; i<M; i++) cin >> B[i];

    int r1 = naiveLCS(A, B, 0, 0);
    cout << "LCS using Naive Recursive Approach: " << r1 << endl;
    cout << "Number of Recursive Function Calls: " << recCalls <<endl;

    int r2 = dpLCS(A, B);
    cout << "LCS using Dynamic Programming: " << r2 << endl;
    cout << "Number of DP Table Computations: " << dpCells << endl;
}
