class Solution {
public:
    // int solve(int index, int buy, vector<int>& prices, vector<vector<int>>& dp){
    //     if(index >= prices.size())
    //         return 0;
    //     if(dp[index][buy]!=-1)
    //         return dp[index][buy];
    //     if(buy){
    //         return dp[index][buy] = max(-prices[index] + solve(index+1, 0, prices, dp),
    //                     0 + solve(index+1, 1, prices, dp));
    //     }
    //     return dp[index][buy] = max(prices[index] + solve(index+2, 1, prices, dp),
    //                 0 + solve(index+1, 0, prices, dp));
    // }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n, vector<int>(2, -1));
        //vector<vector<int>> dp(n+2, vector<int>(2, 0));
        // for(int ind = n-1;ind>=0;ind--){
        //     for(int buy = 0;buy<=1;buy++){
        //         if(buy==1){
        //             dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
        //                                 0 + dp[ind+1][1]);
        //         }
        //         else{
        //             dp[ind][buy] = max(prices[ind] + dp[ind+2][1],
        //                                 0 + dp[ind+1][0]);
        //         }
        //     }
        // }
        //return dp[0][1];
        //return solve(0, 1, prices, dp);
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        vector<int> last(2, 0);
        for(int ind = n-1;ind>=0;ind--){
            curr[1] = max(-prices[ind] + next[0],
                                0 + next[1]);
            curr[0] = max(prices[ind] + last[1],
                                0 + next[0]);
            last = next;
            next = curr;
        }
        return curr[1];

    }
};