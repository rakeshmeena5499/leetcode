class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[0], i, 0});     // Only push all pairs of first array with second arrays first element
        }
        while(k-- && !pq.empty()){
            auto [sum, i, j] = pq.top(); 
            pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if(j<m-1)
                pq.push({nums1[i]+nums2[j+1], i, j+1}); // Here we create new pairs with second arrays elements
        }                                               // while keeping in mind the total k minimum sum pairs
        return res;
    }
};