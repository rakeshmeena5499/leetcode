class Solution {
public:
    int dp[1002];
    int solve(vector<int>& cost, int curr){
        if(curr<0)
            return 0;
        if(curr==0 || curr==1)
            return cost[curr];
        if(dp[curr]!=-1)
            return dp[curr];
        return dp[curr] = cost[curr] + min(solve(cost, curr-1), solve(cost, curr-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));      
        int n = cost.size();
        return min(solve(cost, n-1), solve(cost, n-2));
    }
};