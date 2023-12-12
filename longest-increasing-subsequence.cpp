#include<bits/stdc++.h>
class Solution {
public:
    // int solve(int ind, int prev, vector<int>& nums, int n, vector<vector<int>> dp){
    //     if(ind == n)
    //         return 0;
    //     if(dp[ind][prev+1]!=-1)
    //         return dp[ind][prev+1];
    //     int len = 0 + solve(ind+1, prev, nums, n, dp);
    //     if(prev == -1 || nums[ind] > nums[prev])
    //         len = max(len, 1 + solve(ind+1, ind, nums, n, dp));
    //     return dp[ind][prev+1] = len;
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(0, -1, nums, n, dp);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // for(int ind = n-1;ind>=0;ind--){
        //     for(int prev = ind-1;prev>=-1;prev--){
        //         int len = 0 + dp[ind+1][prev+1];
        //         if(prev == -1 || nums[ind] > nums[prev])
        //             len = max(len, 1 + dp[ind+1][ind+1]);
        //         dp[ind][prev+1] = len;
        //     }
        // }
        // return dp[0][0];

        // vector<int> dp(n, 1);
        // int maxi = 1;
        // for(int i=0;i<n;i++){
        //     for(int prev = 0;prev<i;prev++){
        //         if(nums[prev] < nums[i])
        //             dp[i] = max(dp[i], 1 + dp[prev]);
        //     }
        //     maxi = max(maxi, dp[i]);
        // }
        // return maxi;

        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > lis.back())
                lis.push_back(nums[i]);
            else{
                auto ind = lower_bound(lis.begin(), lis.end(), nums[i]);
                *ind = nums[i];
            }
        }
        return lis.size();
    }
};