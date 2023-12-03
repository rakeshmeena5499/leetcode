int solve(int ind, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
    if(ind == 0){
        if(wt[0] <= W){
            return val[0];
        }
        else{
            return 0;
        }
    }
    int notTake = 0 + solve(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if(wt[ind] <= W){
        take = val[ind] + solve(ind - 1, W - wt[ind], wt, val, dp);
    }
    return dp[ind][W] =  max(notTake, take);
}

int knapsack(vector<int>& weight, vector<int>& value, int n, int maxWeight){
    // Memoization
    // vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    // return solve(n-1, maxWeight, weight, value, dp);


    // Tabulation
    // vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    // for(int W = weight[0];W<=maxWeight;W++){
    //     dp[0][W] = val[0];
    // }

    // for(int i=1;i<n;i++){
    //     for(int W = 0;W<=maxWeight;W++){
    //         int notTake = 0 + dp[ind - 1][W];
    //         int take = INT_MIN;
    //         if(wt[ind] <= W){
    //             take = val[ind] + dp[ind - 1][W - weight[ind]];
    //         }
    //         dp[ind][W] =  max(notTake, take);
    //     }
    // }
    // return dp[n-1][W];

    // Space Optimization
    // vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
    // for(int W = weight[0];W<=maxWeight;W++){
    //     prev[W] = val[0];
    // }
    // for(int i=1;i<n;i++){
    //     for(int W = 0;W<=maxWeight;W++){
    //         int notTake = 0 + prev[W];
    //         int take = INT_MIN;
    //         if(wt[ind] <= W){
    //             take = val[ind] + prev[W - weight[ind]];
    //         }
    //         curr[W] =  max(notTake, take);
    //     }
    //     prev = curr;
    // }
    // return prev[W];

    // More Space Optimized
    vector<int> prev(maxWeight+1, 0);
    for(int W = weight[0];W<=maxWeight;W++){
        prev[W] = val[0];
    }
    for(int i=1;i<n;i++){
        for(int W = maxWeight;W>=0;W--){  // Reversing the for loop won't affect the output
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind] + prev[W - weight[ind]];
            }
            prev[W] =  max(notTake, take);
        }
    }
    return prev[W];
}