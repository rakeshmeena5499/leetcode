class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        vector<int> res;
        while(left<right){
            int sum = nums[left] + nums[right];
            if(sum==target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(sum<target)
                left++;
            else if(sum>target)
                right--;
        }
        return res;
    }
};