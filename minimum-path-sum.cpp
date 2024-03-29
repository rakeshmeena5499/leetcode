class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i==0 && j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0){
    //         return INT_MAX;
    //     }
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int up = 0;
    //     int left = 0;
    //     up = solve(i-1, j, grid, dp);
    //     left = solve(i, j-1, grid, dp);
    //     return dp[i][j] = grid[i][j] + min(up, left);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return solve(m-1, n-1, grid, dp);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dp[i][j] = grid[0][0];
                else{
                    int up = grid[i][j];
                    if(i>0)
                        up += dp[i-1][j];
                    else
                        up+=1e9;
                    int left = grid[i][j];
                    if(j>0)
                        left += dp[i][j-1];
                    else
                        left += 1e9;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];

    }
};