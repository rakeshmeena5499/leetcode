class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long maxi = -1;
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i=2;i<n;i++){
            if(prefix[i-1] > (prefix[i] - prefix[i-1]))
                maxi = max(maxi, prefix[i]);
        }
        return maxi;
    }
};