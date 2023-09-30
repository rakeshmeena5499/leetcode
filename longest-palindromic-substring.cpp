class Solution {
public:
    int expandFromCenter(string& s, int left, int right){
        while((left>=0 && right<s.length()) && (s[left] == s[right])){
            left--;
            right++;
        }
        return right-left-1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;
        for(int i=0;i<n;i++){
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i-((len-1)/2);
                end = i+(len/2);
            }
        }
        string ans = "";
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};