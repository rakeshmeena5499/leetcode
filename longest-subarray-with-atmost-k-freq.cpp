class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLen = 0;
        int start = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                mp[nums[start++]]--;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};