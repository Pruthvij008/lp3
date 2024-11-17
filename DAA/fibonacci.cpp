#include <iostream>
#include <vector>
using namespace std;


int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}


void print_fibonacci_recursive(int n) {
    cout << "Fibonacci series (Recursive): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci_recursive(i) << " ";
    }
    cout << endl;
}

// Iterative  Fibonacci function
void print_fibonacci_iterative(int n) {
    cout << "Fibonacci series (Iterative): ";
    if (n >= 1) cout << 0 << " ";
    if (n >= 2) cout << 1 << " ";
    int a = 0, b = 1, c;
    for (int i = 2; i < n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

// Dynamic Programming (Bottom-Up) Fibonacci function
void print_fibonacci_dp(int n) {
    cout << "Fibonacci series (Dynamic Programming): ";
    if (n >= 1) cout << 0 << " ";
    if (n >= 2) cout << 1 << " ";
    vector<int> dp(n);
    dp[0] = 0;
    if (n > 1) dp[1] = 1;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, n;
    cout << "Fibonacci Series Generator\n";
    cout << "==========================\n";
    cout << "Select an option:\n";
    cout << "1. Recursive Approach\n";
    cout << "2. Non-Recursive (Iterative) Approach\n";
    cout << "3. Dynamic Programming (Bottom-Up) Approach\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the number of terms to display: ";
    cin >> n;

    switch (choice) {
        case 1:
            print_fibonacci_recursive(n);
            break;
        case 2:
            print_fibonacci_iterative(n);
            break;
        case 3:
            print_fibonacci_dp(n);
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
    }

    return 0;
}
