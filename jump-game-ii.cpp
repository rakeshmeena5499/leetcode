class Solution {
public:
    long long int solve(int curr, vector<int>& nums, int end, vector<int>& dp){
        if(curr>=end)
            return 0;
        if(dp[curr]!=-1)
            return dp[curr];
        long long int temp = INT_MAX;
        for(int i=1;i<=nums[curr];i++){
            if(i+curr>end)
                break;
            temp = min(temp, 1+solve(curr+i, nums, end, dp));
        }
        return dp[curr] = temp;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, n-1, dp);
    }
};