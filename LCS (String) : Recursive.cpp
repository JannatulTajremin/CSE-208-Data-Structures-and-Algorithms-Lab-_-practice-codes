#include<bits/stdc++.h>
using namespace std;

string LCS(string A, string B, int i, int j)
{
    if(i == A.size() || j == B.size())
    {
        return "";
    }

    else if(A[i] == B[j])
    {
        return string(1, A[i]) + LCS(A, B, i+1, j+1);
        //string(1, A[i]) here ,1= 1 character,
        //A[i]= the current character which is to convert character to string 
    }

    else
    {
        string x = LCS(A, B, i+1, j);
        string y = LCS(A, B, i, j+1);

        return (x.size() > y.size()) ? x : y;
    }
}

int main()
{
    string A, B;
    cin >> A >> B;

    string result = LCS(A, B, 0, 0);

    cout << result;
}
