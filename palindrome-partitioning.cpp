class Solution {
public:
    bool isPal(string& s, int low, int high){
        while(low<=high){
            if(s[low++]!=s[high--])
                return false;
        }
        return true;
    }

    void solve(string& s, int index, vector<string> curr, vector<vector<string>>& ans){
        if(index==s.size())
            ans.push_back(curr);
        for(int i=index;i<s.size();i++){
            if(isPal(s, index, i)){
                curr.push_back(s.substr(index, i+1-index));
                solve(s, i+1, curr, ans);
                curr.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0, curr, ans);
        return ans;      
    }
};