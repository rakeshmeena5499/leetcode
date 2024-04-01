class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        while(n>=0 && s[n] == ' '){
            n--;
        }
        int i = n;
        while(i>=0 && s[i] != ' '){
            i--;
        }
        return n - i;
    }
};