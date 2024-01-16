class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        else{
            mp[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int n = nums.size();
            int last = nums[n-1];
            int idx_to_remove = mp[val];
            nums[idx_to_remove] = last;
            nums.pop_back();
            mp[last] = idx_to_remove;
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */