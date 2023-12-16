#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007 

int solve(int i, int j, int isTrue, string& exp, vector<vector<vector<int>>>& dp) {
    if (i > j)
        return 0;
    if (i == j) {
        if (isTrue) {
            return exp[i] == 'T';
        }
        else {
            return exp[i] == 'F';
        }
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        long long leftTrue = solve(i, k - 1, 1, exp, dp);
        long long leftFalse = solve(i, k - 1, 0, exp, dp);
        long long rightTrue = solve(k + 1, j, 1, exp, dp);
        long long rightFalse = solve(k + 1, j, 0, exp, dp);
        if (exp[k] == '&') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            }
            else {
                ways = (ways + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        }
        else if (exp[k] == '|') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod + (leftTrue * rightTrue) % mod) % mod;
            }
            else {
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
            }
        }
        else {
            if (isTrue) {
                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            }
            else {
                ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string& exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(0, n - 1, 1, exp, dp);
}

int main() {
    string str = "F|T^F";
    cout << evaluateExp(str);
    return 0;
}