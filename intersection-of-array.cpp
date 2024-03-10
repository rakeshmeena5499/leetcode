class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        for(int n: nums1)
            set1.insert(n);
        vector<int> res;
        for(int i=0;i<nums2.size();i++){
            if(set1.find(nums2[i])!=set1.end()){
                res.push_back(nums2[i]);
                set1.erase(set1.find(nums2[i]));
            }
        }
        return res;
    }
};