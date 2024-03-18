class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1;
        int last = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0] <= last){
                last = min(last, points[i][1]);
            }
            else{
                last = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};