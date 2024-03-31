class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int mini = -1, maxi = -1;
        int start = 0;
        for(int end = 0;end < nums.size();end++){
            if(nums[end] < minK || nums[end] > maxK){
                mini = -1;
                maxi = -1;
                start = end+1;
            }
            if(nums[end] == minK){
                mini = end;
            }
            if(nums[end] == maxK){
                maxi = end;
            }
            ans += max(0, min(mini, maxi) - start + 1);
            //cout << "end: " << end << ", ans: " << ans << ", mini: " << mini << ", maxi: " << maxi << ", start: " << start << endl;
        }
        return ans;
    }
};