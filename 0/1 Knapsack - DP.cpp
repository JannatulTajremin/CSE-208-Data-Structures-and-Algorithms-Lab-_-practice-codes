#include <iostream>
using namespace std;

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    int value[n + 1];
    int weight[n + 1];

    cout << "Enter values:\n";
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    cout << "Enter weights:\n";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    // DP table
    int T[n + 1][W + 1];

    // First row = 0
    for (int c = 0; c <= W; c++) {
        T[0][c] = 0;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {

        for (int c = 0; c <= W; c++) {

            if (weight[i] > c) {
                // Item cannot be taken
                T[i][c] = T[i - 1][c];
            }
            else {
                // Two choices:
                // 1. Don't take the item
                // 2. Take the item

                T[i][c] = max(
                    T[i - 1][c],
                    T[i - 1][c - weight[i]] + value[i]
                );
            }
        }
    }

    cout << "Maximum Value = " << T[n][W] << endl;

    return 0;
}
