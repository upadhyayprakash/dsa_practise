#include <iostream>
#include <cstring>
using namespace std;

// using 'Memoization'
int fibo_memoization(int n, int dp[]) {
    if(n <= 1)
        return n;
    
    if(dp[n] != -1)
        return dp[n];
    int result = fibo_memoization(n-1, dp) + fibo_memoization(n-2, dp);
    dp[n] = result;
    return result;
}

int fibo_tabulation(int n, int dp[]) {
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int dp[n+1];
    memset(dp, -1, sizeof dp);
    cout << "fibo_memoization(" << n << "):\n";
    cout << fibo_memoization(n, dp) << endl;

    cout << "fibo_tabulation(" << n << "):\n";
    cout << fibo_tabulation(n, dp);
    return 0;
}