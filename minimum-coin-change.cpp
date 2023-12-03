class Solution {
public:
    // int solve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
    //     if(ind == 0){
    //         if(target%coins[ind]==0)
    //             return target/coins[ind];
    //         else
    //             return 1e9;
    //     }
    //     if(dp[ind][target] != -1)
    //         return dp[ind][target];
    //     int notTake = 0 + solve(ind - 1, target, coins, dp);
    //     int take = INT_MAX;
    //     if(coins[ind]<=target){
    //         take = 1 + solve(ind, target-coins[ind] , coins, dp);
    //     }
    //     return dp[ind][target] = min(take, notTake);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = solve(n-1, amount, coins, dp);
        // if(ans >= 1e9)
        //     return -1;
        // else
        //     return ans;

        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // for(int target = 0;target<=amount;target++){
        //     if(target%coins[0]==0)
        //         dp[0][target] = target/coins[0];
        //     else
        //         dp[0][target] = 1e9;
        // }

        // for(int ind = 1;ind<n;ind++){
        //     for(int target = 0;target<=amount;target++){
        //         int notTake = 0 + dp[ind - 1][target];
        //         int take = INT_MAX;
        //         if(coins[ind]<=target){
        //             take = 1 + dp[ind][target-coins[ind]];
        //         }
        //         dp[ind][target] = min(take, notTake);
        //     }
        // }
        // int ans = dp[n-1][amount];
        // if(ans >= 1e9)
        //     return -1;
        // else
        //     return ans;

        vector<int> prev(amount+1, 0);
        for(int target = 0;target<=amount;target++){
            if(target%coins[0]==0)
                prev[target] = target/coins[0];
            else
                prev[target] = 1e9;
        }

        for(int ind = 1;ind<n;ind++){
            for(int target = 0;target<=amount;target++){
                int notTake = 0 + prev[target];
                int take = INT_MAX;
                if(coins[ind]<=target){
                    take = 1 + prev[target-coins[ind]];
                }
                prev[target] = min(take, notTake);
            }
        }
        int ans = prev[amount];
        if(ans >= 1e9)
            return -1;
        else
            return ans;
    }
};