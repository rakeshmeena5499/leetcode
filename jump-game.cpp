class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, i = 0;
        for(i = 0;i<nums.size();i++){
            if(farthest<i)
                return 0;
            farthest = max(i+nums[i], farthest);
        }
        return i==nums.size();
    }
};