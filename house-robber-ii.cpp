class Solution {
public:
    int dp[102];
    int solve(vector<int>& nums, int idx, int last){
        if(idx<last)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx] = max(nums[idx] + solve(nums, idx-2, last), solve(nums, idx-1, last));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return n?nums[0]:0;
        int a = 0, b = 0;
        memset(dp, -1, sizeof(dp));
        a = solve(nums, n-1, 1);
        memset(dp, -1, sizeof(dp));
        b = solve(nums, n-2, 0);
        return max(a, b);
    }
};