class Solution {
public:
    // int solve(int index, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp){
    //     if(index == prices.size())
    //         return 0;
    //     if(dp[index][buy]!=-1)
    //         return dp[index][buy];
    //     if(buy){
    //         return dp[index][buy] = max(-prices[index] + solve(index+1, 0, prices, fee, dp), 
    //                     0 + solve(index+1, 1, prices, fee, dp));
    //     }
    //     return dp[index][buy] = max(prices[index] - fee + solve(index+1, 1, prices, fee, dp),
    //                     0 + solve(index+1, 0, prices, fee, dp));
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //vector<vector<int>> dp(n, vector<int>(2, -1));
        vector<int> after(2, 0);
        vector<int> curr(2, 0);
        for(int ind = n-1;ind>=0;ind--){
            curr[1] = max(-prices[ind] + after[0], 
                        0 + after[1]);
            curr[0] = max(prices[ind] - fee + after[1],
                        0 + after[0]);
            after = curr;
        }
        return curr[1];
        //return solve(0, 1, prices, fee, dp);
    }
};