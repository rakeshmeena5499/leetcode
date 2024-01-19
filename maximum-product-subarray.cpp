class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int imax = 1;
        int imin = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                swap(imax, imin);
            }
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            ans = max(ans, imax);
        }
        return ans;
    }
};