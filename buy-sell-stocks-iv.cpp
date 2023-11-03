class Solution {
public:
    // int solve(int index, int buy, int k, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
    //     if(index == n || k == 0)
    //         return 0;
    //     if(dp[index][buy][k]!=-1)
    //         return dp[index][buy][k];
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[index] + solve(index+1, 0, k, prices, n, dp), 
    //                     0 + solve(index+1, 1, k, prices, n, dp));
    //     }
    //     else{
    //         profit = max(prices[index] + solve(index+1, 1, k-1, prices, n, dp),
    //                     0 + solve(index+1, 0, k, prices, n, dp));
    //     }
    //     return dp[index][buy][k] = profit;
    // }

    // int solve(int ind, int transNo, int k, vector<int>& prices, int n, vector<vector<int>>& dp){
    //     if(ind == n || transNo == 2*k)
    //         return 0;
    //     if(dp[ind][transNo]!=-1)
    //         return dp[ind][transNo];
    //     if(transNo%2==0){
    //         return dp[ind][transNo] = max(-prices[ind] + solve(ind+1, transNo+1, k, prices, n, dp),
    //                     0 + solve(ind+1, transNo, k, prices, n, dp));
    //     }
    //     return dp[ind][transNo] = max(prices[ind] + solve(ind+1, transNo+1, k, prices, n, dp),
    //                 0 + solve(ind+1, transNo, k, prices, n, dp));
    // }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        //vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        vector<int> after(2*k+1, 0);
        vector<int> curr(2*k+1, 0);
        for(int ind = n-1; ind >= 0; ind--){
            for(int transNo = 2*k-1; transNo >= 0; transNo--){
                if(transNo%2==0){
                    curr[transNo] = max(-prices[ind] + after[transNo+1],
                                0 + after[transNo]);
                }
                else{
                    curr[transNo] = max(prices[ind] + after[transNo+1],
                            0 + after[transNo]);
                }
            }
            after = curr;
        }
        return after[0];
        //return solve(0, 0, k, prices, n, dp);
    }
};