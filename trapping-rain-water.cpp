class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // vector<int> left(n, 0);
        // vector<int> right(n, 0);
        // left[0] = height[0];
        // for(int i=1;i<n;i++){
        //     left[i] = max(height[i], left[i-1]);
        // }
        // right[n-1] = height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     right[i] = max(height[i], right[i+1]);
        // }
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     ans += min(left[i], right[i]) - height[i];
        // }
        // return ans;

        int n = height.size();
        int left = 0, right = n-1;
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int ans = 0;
        while(left<=right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax < rightMax){
                ans += leftMax - height[left++];
            }
            else{
                ans += rightMax - height[right--];
            }
        }
        return ans;
    }
};