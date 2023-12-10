class Solution {
public:
    int solve(int ind, int target, vector<int>& nums){
        if(ind == 0){
            if(target == 0 && nums[0] == 0)
                return 2;
            if(target == 0 || target == nums[0])
                return 1;
            return 0;
        }
        int notTake = solve(ind - 1, target, nums);
        int take = 0;
        if(nums[ind]<=target){
            take = solve(ind - 1, target - nums[ind], nums);
        }
        return take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums)
            totalSum += num;
        
        if((totalSum - target) < 0 || (totalSum - target)%2)
            return 0;
        return solve(n-1, (totalSum - target)/2, nums);   
    }
};