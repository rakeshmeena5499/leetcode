class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> res;
        // res.push_back(intervals[0]);
        // for(int i=1;i<intervals.size();i++){
        //     if(res.back()[1]>=intervals[i][0])
        //         res.back()[1] = max(res.back()[1], intervals[i][1]);
        //     else
        //         res.push_back(intervals[i]);
        // }
        // return res;

        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // Case 1: no overlapping from front
        while(i<n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        // Case 2 : Merge overlapping intervals
        while(i<n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        //Case 3 : no overlapping after merging
        while(i<n){
            res.push_back(intervals[i++]);
        }
        return res;
    }
};