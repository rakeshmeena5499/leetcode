class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
    //     if(j<0 || j>=mat[0].size())
    //         return 1e8;
    //     if(i==0)
    //         return mat[0][j];
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int left = mat[i][j] + solve(i-1, j-1, mat, dp);
    //     int up = mat[i][j] + solve(i-1, j, mat, dp);
    //     int right = mat[i][j] + solve(i-1, j+1, mat, dp);
    //     return dp[i][j] = min(left, min(up, right));
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // int mini = 1e9;
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // for(int j = 0;j<n;j++)
        //     mini = min(mini, solve(m-1, j, matrix, dp));
        // return mini;

        //vector<vector<int>> dp(m, vector<int>(n, 0));

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int j = 0;j<n;j++){
            prev[j] = matrix[0][j];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<m;j++){
                int left = matrix[i][j];
                if(j-1>=0) left += prev[j-1];
                else left += 1e8;
                int up = matrix[i][j] + prev[j];
                int right = matrix[i][j];
                if(j+1<m) right += prev[j+1];
                else right += 1e8;
                curr[j] = min(left, min(up, right));
            }
            prev = curr;
        }
        int mini = 1e8;
        for(int j = 0;j<n;j++)
            mini = min(mini, prev[j]);
        return mini;
    }
};