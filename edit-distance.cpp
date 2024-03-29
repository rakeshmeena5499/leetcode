class Solution {
public:
    // int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
    //     if(i<0)
    //         return j+1;
    //     if(j<0)
    //         return i+1;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(s[i] == t[j])
    //         return dp[i][j] = 0 + solve(i-1, j-1, s, t, dp);
    //     else
    //         return dp[i][j] = 1 + min(solve(i, j-1, s, t, dp), min(solve(i-1, j, s, t, dp), solve(i-1, j-1, s, t, dp)));
    // }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, word1, word2, dp);

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for(int i=0;i<=n;i++)
        //     dp[i][0] = i;
        // for(int j=0;j<=m;j++)
        //     dp[0][j] = j;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(word1[i-1] == word2[j-1])
        //             dp[i][j] = 0 + dp[i-1][j-1];
        //         else
        //             dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        //     }
        // }
        // return dp[n][m];

        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int j=0;j<=m;j++)
            prev[j] = j;
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1])
                    curr[j] = 0 + prev[j-1];
                else
                    curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};