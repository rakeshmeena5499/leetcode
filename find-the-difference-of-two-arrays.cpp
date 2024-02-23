class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<vector<int>> ans;
        vector<int> temp;
        for(auto it : set1){
            if(set2.find(it) == set2.end())
                temp.push_back(it);
        }
        ans.push_back(temp);
        temp.clear();
        for(auto it : set2){
            if(set1.find(it) == set1.end())
                temp.push_back(it);
        }
        ans.push_back(temp);
        return ans;
    }
};