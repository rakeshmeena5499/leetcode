class Solution {
public:
    // int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp){
    //     if(i<0 || j<0)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(s1[i] == s2[j])
    //         return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
    //     else
    //         return dp[i][j] = 0 + max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    // }

    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, str1, str2, dp);
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        // for(int i=0;i<=n;i++)
        //     dp[i][0] = 0;
        for(int j=0;j<=m;j++)
            prev[j] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};