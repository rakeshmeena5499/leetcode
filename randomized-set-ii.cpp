class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, vector<int>> mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        mp[val].push_back(nums.size());
        nums.push_back(val);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end() || mp[val].size() == 0){
            return false;
        }
        else{
            int index = mp[val][mp[val].size() - 1];
            int last = nums.back();
            nums[index] = last;
            mp[last].pop_back();
            mp[last].push_back(index);
            sort(mp[last].begin(), mp[last].end());         // Not actually truely O(1) due to this sort, set could help in place of vector
            nums.pop_back();
            mp[val].pop_back();
            return true;
        }
    }
    
    int getRandom() {
        int idx = rand()%nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */