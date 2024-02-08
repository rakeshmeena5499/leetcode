class Solution {
public:
    int solve(int ind, int target, vector<vector<int>>& dp, vector<int>& squares){
        if(ind==0){
            if(target%squares[0]==0)
                return target/squares[0];
            else
                return 1e9;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int notTake = 0 + solve(ind-1, target, dp, squares);
        int take = INT_MAX;
        if(squares[ind]<=target){
            take = 1 + solve(ind, target - squares[ind], dp, squares);
        }
        return dp[ind][target] = min(take, notTake);
    }

    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> squares;
        for(int i=1;i<=m;i++){
            squares.push_back(i*i);
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n, dp, squares);
    }
};