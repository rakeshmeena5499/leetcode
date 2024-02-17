class Solution {
public:
    // int solve(int i, int bricks, int ladders, vector<int>& heights, vector<vector<vector<int>>>& dp){
    //     if(i+1>=heights.size())
    //         return 0;
    //     if(dp[i][bricks][ladders]!=-1)
    //         return dp[i][bricks][ladders];
    //     if(heights[i+1] <= heights[i]){
    //         return dp[i][bricks][ladders] = 1 + solve(i+1, bricks, ladders, heights, dp);
    //     }
    //     int brick = 0, ladder = 0;
    //     if(bricks >= heights[i+1] - heights[i]){
    //         brick = 1 + solve(i+1, bricks - (heights[i+1] - heights[i]), ladders, heights, dp);
    //     }
    //     if(ladders > 0){
    //         ladder = 1 + solve(i+1, bricks, ladders - 1, heights, dp);
    //     }
    //     return dp[i][bricks][ladders] = max(brick, ladder);
    // }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // vector<vector<vector<int>>> dp(heights.size()+1, vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1)));
        // return solve(0, bricks, ladders, heights, dp);

        int n = heights.size();
        priority_queue<int> pq;
        for(int i=0;i<n-1;i++){
            int diff = heights[i+1] - heights[i];
            if(diff > 0){
                pq.push(-diff);
            }
            if(pq.size() > ladders){
                bricks += pq.top();
                pq.pop();
            }
            if(bricks < 0){
                return i;
            }
        }
        return n-1;
    }
};