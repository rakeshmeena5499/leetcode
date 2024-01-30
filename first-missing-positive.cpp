class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){ // Only concerned about the positions of 
                swap(nums[i], nums[nums[i]-1]);                         // numbers between 1 to n to be correct.
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};