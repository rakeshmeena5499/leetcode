class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int maxElementFreq = 0;
        int start = 0;
        long long ans = 0;
        for(int end = 0;end<nums.size();end++){
            if(nums[end] == maxElement){
                maxElementFreq++;
            }
            while(maxElementFreq == k){
                if(nums[start] == maxElement){
                    maxElementFreq--;
                }
                start++;
            }
            ans += start;
        }
        return ans;
    }
};