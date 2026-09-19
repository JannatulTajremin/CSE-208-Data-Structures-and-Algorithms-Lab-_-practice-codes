#include<bits/stdc++.h>
using namespace std;

int LCS(vector<int>& A, vector<int>& B, int i, int j)
{
    if(i == (int)A.size() || j == (int)B.size())
        return 0;

    else if(A[i] == B[j])
        return 1 + LCS(A, B, i+1, j+1);

    else
        return max(LCS(A, B, i+1, j),
                   LCS(A, B, i, j+1));
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);

    for(int i=0; i<N; i++)
        cin >> A[i];

    for(int i=0; i<M; i++)
        cin >> B[i];

    int result = LCS(A, B, 0, 0);

    cout << result;

    return 0;
}
