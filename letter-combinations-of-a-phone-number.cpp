class Solution {
public:
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void solve(string digits, int index, string& curr){
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }
        for(char ch : mappings[digits[index] - '2']){
            curr.push_back(ch);
            solve(digits, index + 1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        string curr = "";
        solve(digits, 0, curr);
        return ans;
    }
};