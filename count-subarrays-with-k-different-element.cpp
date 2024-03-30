class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int start = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int end = 0;end<n;end++){
            mp[nums[end]]++;
            while(mp.size() > k){
                mp[nums[start]]--;
                if(mp[nums[start]] == 0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            ans += (end - start + 1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};