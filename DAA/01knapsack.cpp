// #include <bits/stdc++.h>
// using namespace std;

// int static t[101][101];

// int knapsack01(int wt[], int val[], int w, int n) {
//     for (int i = 0; i < n + 1; i++) {
//         for (int j = 0; j < w + 1; j++) {
//             if (i == 0 || j == 0) {
//                 t[i][j] = 0;
//             }
//         }
//     }

//     for (int i = 1; i < n + 1; i++) {
//         for (int j = 1; j < w + 1; j++) {
//             if (wt[i - 1] <= j) {
//                 t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
//             } else {
//                 t[i][j] = t[i - 1][j];
//             }
//         }
//     }

//     return t[n][w];
// }

// int main() {
//     int n = 4;           // Number of items
//     int w = 8;           // Maximum weight capacity
//     int wt[] = {1, 3, 4, 5};   // Weights of items
//     int val[] = {1, 4, 5, 7};  // Values of items

//     cout << "Maximum value in knapsack = " << knapsack01(wt, val, w, n) << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int static t[101][101];

int knapsack01(int wt[], int val[], int w, int n) {
    // Initialize the DP table
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    // Fill the DP table
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            if (wt[i - 1] <= j) {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // Track which items were included in the knapsack
    int res = t[n][w];
    int W = w;
    cout << "Items included in the knapsack (Value, Weight):" << endl;
    
    for (int i = n; i > 0 && res > 0; i--) {
        // If the item is included in the optimal solution
        if (res != t[i - 1][W]) {
            cout << "(" << val[i - 1] << ", " << wt[i - 1] << ")" << endl;
            // Deduct the item's value and weight
            res -= val[i - 1];
            W -= wt[i - 1];
        }
    }

    return t[n][w];
}

int main() {
    int n = 4;                   // Number of items
    int w = 8;                   // Maximum weight capacity
    int wt[] = {1, 3, 4, 5};     // Weights of items
    int val[] = {1, 4, 5, 7};    // Values of items

    cout << "Maximum value in knapsack = " << knapsack01(wt, val, w, n) << endl;
    return 0;
}
