class Solution {
public:
    void solve(vector<string>& res, string ans, int left, int right){
        if(left==0 && right==0){
            res.push_back(ans);
            return;
        }
        if(left>0){
            solve(res, ans+"(", left-1, right);
        }
        if(right>left){
            solve(res, ans+")", left, right-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res, "", n, n);
        return res;
    }
};