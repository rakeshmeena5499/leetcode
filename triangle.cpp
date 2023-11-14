class Solution {
public:
    // int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    //     if(i==n-1)
    //         return triangle[i][j];
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int down = triangle[i][j] + solve(i+1, j, n, triangle, dp);
    //     int diag = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
    //     return dp[i][j] = min(down, diag);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, 0, n, triangle, dp);
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> front(n, 0), curr(n, 0);
        for(int j=0;j<n;j++){
            front[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                curr[j] = min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }
};