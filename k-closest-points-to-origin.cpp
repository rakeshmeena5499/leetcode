class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int> vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<points.size();i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dist, i});
        }      
        while(!pq.empty() && k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};