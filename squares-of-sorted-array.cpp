class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squares(n, 0);
        int low = 0, high = n-1;
        int i = n-1;
        while(low<=high){
            if(abs(nums[low]) <= abs(nums[high])){
                squares[i--] = nums[high]*nums[high--];
            }
            else{
                squares[i--] = nums[low]*nums[low++];
            }
        }
        return squares;
    }
};