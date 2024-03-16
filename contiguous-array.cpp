class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int ans = 0;
        int i = 0;
        for(int num : nums){
            if(num){
                sum += 1;
            }
            else{
                sum -= 1;
            }
            if(mp.find(sum)!=mp.end()){
                ans = max(ans, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
            i++;
        }
        return ans;
    }
};