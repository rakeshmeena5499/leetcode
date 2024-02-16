class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int, int>> freq;
        for(auto it : mp){
            freq.push_back({it.first, it.second});
        }
        sort(freq.begin(), freq.end(), comp);
        int ans = freq.size();
        for(int i=0;i<freq.size();i++){
            if(freq[i].second <= k){
                k -= freq[i].second;
                freq[i].second = 0;
                ans--;
            }
        }
        return ans;
    }
};