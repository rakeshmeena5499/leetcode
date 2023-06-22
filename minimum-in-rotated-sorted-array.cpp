class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        int ans = nums[0];
        while(lo<=hi){
            if(nums[lo]<nums[hi]){
                ans = min(ans, nums[lo]);
                break;
            }
            int mid = lo + (hi - lo)/2;
            ans = min(ans, nums[mid]);
            if(nums[lo]<=nums[mid]){
                lo = mid+1;
            else
                hi = mid-1;
            }
        }     
        return ans;
    }
};