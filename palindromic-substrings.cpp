class Solution {
public:
    int count(string& s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.size() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int total = 0;
        for(int i=0;i<s.size();i++){
            int left = count(s, i, i);
            int right = count(s, i, i+1);
            total += left + right;
        }
        return total;
    }
};