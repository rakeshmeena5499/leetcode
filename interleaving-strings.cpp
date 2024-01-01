class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<int>>& dp){
        if(i<0 && j<0 && k<0)
            return true;
        if(i>=0 && j>=0 && dp[i][j] != -1){
            return dp[i][j];
        }
        if(i>=0 && s1[i]==s3[k] && j>=0 && s2[j]==s3[k]){
            return dp[i][j] = solve(s1, s2, s3, i-1, j, k-1, dp) || solve(s1, s2, s3, i, j-1, k-1, dp);
        }
        else if(i>=0 && s1[i]==s3[k]){
            return solve(s1, s2, s3, i-1, j, k-1, dp);
        }
        else if(j>=0 && s2[j]==s3[k]){
            return solve(s1, s2, s3, i, j-1, k-1, dp);
        } 
        else{
            return false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        if(m+n != l)
            return false;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s1, s2, s3, n-1, m-1, l-1, dp);
    }
};