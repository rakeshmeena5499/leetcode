class Solution {
public:
    // int solve(int index, vector<int>& heights, vector<int>& dp){
    //     if(index == 0)
    //         return 0;
    //     if(dp[index]!=-1)
    //         return dp[index];
    //     int left = solve(index-1, heights) + abs(heights[index] - heights[index-1]);
    //     int right = 0;
    //     if(index>1){
    //         right = solve(index-2, heights) + abs(heights[index] - heights[index-2]);
    //     }
    //     return dp[index] = min(left, right);
    // }

    int frogJump(int n, vector<int> &heights){
        //vector<int> dp(n, -1); 
        //return solve(n, heights);
        //vector<int> dp(n, 0);
        //dp[0] = 0;
        // for(int i=1;i<n;i++){
        //     int firstStep = dp[i-1] + abs(heights[i] - heights[i-1]);
        //     int secondStep = INT_MAX;
        //     if(i>1){
        //         secondStep = dp[i-2] + abs(heights[i] - heights[i-2]);
        //     }
        //     dp[i] = min(firstStep, secondStep);
        // }
        // return dp[n-1];
        int prev = 0;
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int firstStep = prev + abs(heights[i] - heights[i-1]);
            int secondStep = INT_MAX;
            if(i>1){
                secondStep = prev2 + abs(heights[i] - heights[i-2]);
            }
            int curr = min(prev, prev2);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};