class Solution {
public:
    int binarySearchLeft(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }

    int binarySearchRight(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearchLeft(nums, target);
        int right = binarySearchRight(nums, target);
        if(left<=right)
            return {left, right};
        else
            return {-1, -1};
    }
};