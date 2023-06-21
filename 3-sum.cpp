class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum<0){
                    left++;
                }
                else if(sum>0){
                    right--;
                } 
                else{
                    vector<int> ans(3, 0);
                    ans[0] = nums[i];
                    ans[1] = nums[left];
                    ans[2] = nums[right];
                    res.push_back(ans);
                    while(left<right && nums[left]==ans[1]){
                        left++;
                    }
                    while(left<right && nums[right]==ans[2]){
                        right--;
                    }
                }
            }
            while(i+1<n && nums[i+1]==nums[i])
                i++;
        }
        return res;
    }
};