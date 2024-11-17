// #include <bits/stdc++.h>
// using namespace std;

// class Nqueens {
// public:
//     Nqueens(int n) {
//         N = n;
//         board = vector<vector<char>>(N, vector<char>(N, '.'));
//         solutionFound = false;
//     }

//     void solve(bool findAllSolutions) {
//         solutionFound = false;
//         PlaceQueens(0, findAllSolutions);
//         if (!solutionFound) {
//             cout << "No solution exists for " << N << "-Queens problem." << endl;
//         }
//     }

// private:
//     int N;
//     bool solutionFound;
//     vector<vector<char>> board;

//     void PlaceQueens(int row, bool findAllSolutions) {
//         if (row == N) {
//             printboard();
//             solutionFound = true;
//             if (!findAllSolutions) return;  // Stop if only one solution is needed
//         }
//         for (int col = 0; col < N; col++) {
//             if (isSafe(row, col)) {
//                 board[row][col] = 'Q';
//                 PlaceQueens(row + 1, findAllSolutions);
//                 if (solutionFound && !findAllSolutions) return;  // Stop further recursion if one solution is found
//                 board[row][col] = '.';
//             }
//         }
//     }

//     bool isSafe(int row, int col) {
//         for (int i = 0; i < row; i++) {
//             if (board[i][col] == 'Q')
//                 return false;
//         }
//         for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//             if (board[i][j] == 'Q')
//                 return false;
//         }
//         for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
//             if (board[i][j] == 'Q')
//                 return false;
//         }
//         return true;
//     }

//     void printboard() {
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 cout << board[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int n, choice;
//     cout << "Enter the value of N: ";
//     cin >> n;

//     cout << "Choose an option:\n";
//     cout << "1. Find one solution\n";
//     cout << "2. Find all solutions\n";
//     cout << "Enter your choice (1 or 2): ";
//     cin >> choice;

//     Nqueens queens(n);

//     if (choice == 1) {
//         cout << "One solution for " << n << "-Queens problem:\n";
//         queens.solve(false);  // Find only one solution
//     } else if (choice == 2) {
//         cout << "All solutions for " << n << "-Queens problem:\n";
//         queens.solve(true);  // Find all solutions
//     } else {
//         cout << "Invalid choice!" << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class Nqueens {
public:
    Nqueens(int n) {
        N = n;
        board = vector<vector<char>>(N, vector<char>(N, '.'));
    }

    void solve() {
        PlaceQueens(0);
    }

private:
    int N;
    vector<vector<char>> board;

    void PlaceQueens(int row) {
        if (row == N) {
            printboard();
            return;
        }
        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 'Q';
                PlaceQueens(row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col) {
        // Check the column for any queens
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check the upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check the upper right diagonal
        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        // If no conflicts, the position is safe
        return true;
    }

    void printboard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    Nqueens queens(n);
    cout << "Solutions for " << n << "-Queens problem:\n";
    queens.solve();

    return 0;
}
