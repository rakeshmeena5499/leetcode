int solve(int ind, int n, vector<int>& price, vector<vector<int>>& dp){
    if(ind == 0){
        return n*price[0];
    }
    if(dp[ind][n]!=-1)
        return dp[ind][n];
    int notTake = 0 + solve(ind - 1, n, price, dp);
    int take = INT_MIN;
    int rodLen = ind + 1;
    if(rodLen <= n){
        take = price[ind] + solve(ind, n - rodLen, price, dp);
    }
    return dp[ind][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return solve(n-1, n, price, dp);
}