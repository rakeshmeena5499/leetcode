int lcs(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];    // Can be further space optimized by using 
                ans = max(ans, dp[i][j]);       // prev and curr rows only instead of whole dp vector.
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}