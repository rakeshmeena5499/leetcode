class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numXor = 0, trueXor = 0;
        for(int i=0;i<nums.size();i++){
            numXor ^= nums[i];
            trueXor ^= (i+1);
        }
        return numXor ^ trueXor;
    }
};