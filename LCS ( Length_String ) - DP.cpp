
#include<bits/stdc++.h>
using namespace std;

int LCS(string A, string B)
{
    int m = A.size();
    int n = B.size();

    // 2D table
    //vector<vector<int>> C(rows, vector<int>(columns, initial_value));
    vector<vector<int>> C(m+1, vector<int>(n+1, 0));

    // Visit every cell
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // If characters are same
            if(A[i-1] == B[j-1])
            {
                C[i][j] = C[i-1][j-1] + 1;
            }

            // If characters are different
            else
            {
                C[i][j] = max(C[i-1][j], C[i][j-1]);
            }
        }
    }

    return C[m][n];
}

int main()
{
    string A, B;

    cin >> A >> B;

    int result = LCS(A, B);

    cout << result;

    return 0;
}
