class Solution {
public:
    int mod = 1e9+7;
    int solve(int i, int j, int m, int n, int maxMove, vector<vector<vector<long long int>>>& dp){
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if (maxMove == 0) {
            return 0;
        }
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove];
        long long int up = solve(i-1, j, m, n, maxMove-1, dp)%mod;
        long long int down = solve(i+1, j, m, n, maxMove-1, dp)%mod;
        long long int left = solve(i, j-1, m, n, maxMove-1, dp)%mod;
        long long int right = solve(i, j+1, m, n, maxMove-1, dp)%mod;
        return dp[i][j][maxMove] = (up + down + left + right)%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long int>>> dp(m, vector<vector<long long int>>(n, vector<long long int>(maxMove+1, -1)));
        return solve(startRow, startColumn, m, n, maxMove, dp);    
    }
};