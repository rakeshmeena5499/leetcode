class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up = 0;
        if(i-1>=0 && matrix[i-1][j] > matrix[i][j])
            up = 1 + solve(i-1, j, matrix, dp);
        int right = 0;
        if(j+1<matrix[0].size() && matrix[i][j+1] > matrix[i][j])
            right = 1 + solve(i, j+1, matrix, dp);
        int down = 0;
        if(i+1<matrix.size() && matrix[i+1][j] > matrix[i][j])
            down = 1 + solve(i+1, j, matrix, dp);
        int left = 0;
        if(j-1>=0 && matrix[i][j-1] > matrix[i][j])
            left = 1 + solve(i, j-1, matrix, dp);
        return dp[i][j] = max(max(up, right), max(down, left));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, 1 + solve(i, j, matrix, dp));
            }
        }
        return ans;
    }
};