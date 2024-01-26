class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minSum = INT_MAX;
        int ans = 0;
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < minSum){
                    minSum = abs(sum - target);
                    ans = sum;
                }
                if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
                else{
                    ans = sum;
                    i = n;      // To get out of the outer for loop as we've sum = target
                    break;
                }
            }
        }
        return ans;      
    }
};