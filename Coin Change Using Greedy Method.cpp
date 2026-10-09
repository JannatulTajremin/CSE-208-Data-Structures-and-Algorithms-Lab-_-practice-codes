
#include <bits/stdc++.h>
using namespace std;


int greedyCoinChange(vector<int>& c, int n, int i)
{
    if (n == 0)
        return 0;

    if (i == c.size())
        return -1;

    if (c[i] <= n)
    {
        int result = greedyCoinChange(c, n - c[i], i);

        if (result == -1)
            return -1;

        return 1 + result;
    }
    else
    {
        return greedyCoinChange(c, n, i + 1);
    }
}

int main()
{
    int n, size;
    
    cout << "Enter amount: ";
    cin >> n;

    cout << "Enter number of coins: ";
    cin >> size;

    vector<int> c(size);

    cout << "Enter coin denominations in random order: ";
    for (int i = 0; i < size; i++)
    {
        cin >> c[i];
    }

    sort(c.rbegin(), c.rend());

    int totalCoins = greedyCoinChange(c, n, 0);

    if (totalCoins == -1)
        cout << "Amount cannot be formed";
    else
        cout << "Total Coins = " << totalCoins << endl;

    return 0;
}
