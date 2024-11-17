#include <bits/stdc++.h>
using namespace std;

class Nqueens {
public:
    Nqueens(int n) {
        N = n;
        board = vector<vector<char>>(N, vector<char>(N, '.'));
        foundSolution = false; // Initialize to false
    }

    void solve() {
        PlaceQueens(0);
    }

private:
    int N;
    vector<vector<char>> board;
    bool foundSolution; // Flag to check if a solution is found

    void PlaceQueens(int row) {
        if (foundSolution) return; // Stop if a solution has been found

        if (row == N) {
            printboard();
            foundSolution = true; // Mark that we've found a solution
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 'Q';
                PlaceQueens(row + 1);
                board[row][col] = '.'; // Backtrack
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
    cout << "One solution for the " << n << "-Queens problem:\n";
    queens.solve();

    return 0;
}
