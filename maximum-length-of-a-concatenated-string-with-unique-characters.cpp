class Solution {
public:
    void dfs(vector<string>& arr, string path, int idx, int& res){
        if(isUniquePath(path)){
            res = max(res, static_cast<int>(path.size()));
        }
        if(idx == arr.size() || !isUniquePath(path)){
            return;
        }
        for(int i=idx;i<arr.size();i++){
            dfs(arr, path + arr[i], i+1, res);
        }
    }

    bool isUniquePath(string path){
        vector<int> freq(26, 0);
        for(int i=0;i<path.size();i++){
            if(freq[path[i] - 'a'] == 0)
                freq[path[i] - 'a'] = 1;
            else
                return false;
        }
        return true;
    }

    int maxLength(vector<string>& arr) {
        int res = 0;
        string path = "";
        dfs(arr, path, 0, res);
        return res;
    }
};