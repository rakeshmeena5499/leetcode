class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(mp.find(diff)!=mp.end()){
                res.push_back(mp[diff]);
                res.push_back(i);
            }
            else{
                mp[nums[i]] = i;
            }
        }      
        return res;
    }
};