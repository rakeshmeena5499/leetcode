class Solution {
public:
    // bool solve(int i, int j, string& pat, string& str, vector<vector<int>>& dp){
    //     if(i==0 && j==0)
    //         return true;
    //     if(i==0 && j>0)
    //         return false;
    //     if(j==0 && i>0){
    //         for(int k=1;k<=i;k++)
    //             if(pat[k-1]!='*')
    //                 return false;
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(pat[i-1] == str[j-1] || pat[i-1] == '?')
    //         return dp[i][j] = solve(i-1, j-1, pat, str, dp);
    //     if(pat[i-1] == '*')
    //         return dp[i][j] = solve(i-1, j, pat, str, dp) | solve(i, j-1, pat, str, dp);
    //     return dp[i][j] = false;
    // }

    bool isMatch(string str, string pat) {
        int n = str.size();
        int m = pat.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solve(m, n, p, s, dp);

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int j=1;j<=n;j++)
            dp[0][j] = false;
        for(int i=1;i<=m;i++){
            int flag = true;
            for(int k=1;k<=i;k++){
                if(pat[k-1]!='*'){
                    flag = false; 
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(pat[i-1] == str[j-1] || pat[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(pat[i-1] == '*')
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};