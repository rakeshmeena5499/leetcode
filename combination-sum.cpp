class Solution {
public:
    void solve(int start, int target, vector<int>& nums, vector<int> curr, vector<vector<int>>& ans){
        if(target==0)
            ans.push_back(curr);
        if(target<0)
            return;
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            solve(i, target-nums[i], nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, nums, curr, ans);
        return ans;
    }
};