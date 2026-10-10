#include <bits/stdc++.h>
using namespace std;

double knapsack(int weight[], int profit[], int n, int capacity)
{
    // Sort according to profit/weight ratio
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if((double)profit[i] / weight[i] <(double)profit[j] / weight[j])
            {
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    double totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        if(capacity == 0)
            break;

        if(weight[i] <= capacity)
        {
            totalProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            totalProfit += (double)profit[i] / weight[i] * capacity;
            capacity = 0;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], profit[n];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter weight and profit of item "
             << i + 1 << ": ";
        cin >> weight[i] >> profit[i];
    }

    double result = knapsack(weight, profit, n, capacity);

    cout << "Maximum Profit = " << result << endl;

}
