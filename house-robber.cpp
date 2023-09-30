class Solution {
public:
    int dp[102];
    int solve(vector<int>& nums, int i){
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = max(nums[i] + solve(nums, i-2), solve(nums, i-1));
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, nums.size()-1);
    }
};