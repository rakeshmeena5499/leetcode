class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> buckets(n+1);
        for(auto it: mp){
            buckets[it.second].push_back(it.first);
        }

        vector<int> res;
        for(int i=n;i>=0;i--){
            if(res.size()==k)
                break;
            if(!buckets[i].empty()){
                res.insert(res.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return res;
    }
};