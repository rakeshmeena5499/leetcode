class Solution {
public:
    // int solve(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
    //     if(ind==n || cap==0)
    //         return 0;
    //     if(dp[ind][buy][cap]!=-1)
    //         return dp[ind][buy][cap];
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[ind] + solve(ind+1, 0, cap, prices, n, dp),
    //                      0 + solve(ind+1, 1, cap, prices, n, dp));
    //     }
    //     else{
    //         profit = max(prices[ind] + solve(ind+1, 1, cap-1, prices, n, dp),
    //                     0 + solve(ind+1, 0, cap, prices, n, dp));
    //     }
    //     return dp[ind][buy][cap] = profit;
    // }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0, 1, 2, prices, n, dp);
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                    if(buy){
                        curr[buy][cap] = max(-prices[ind] + after[0][cap],
                                    0 + after[1][cap]);
                    }
                    else{
                        curr[buy][cap] = max(prices[ind] + after[1][cap-1],
                                    0 + after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        return after[1][2];
    }
};