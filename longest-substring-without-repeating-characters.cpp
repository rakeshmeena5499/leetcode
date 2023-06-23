class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = s.size();
        set<char> st;
        while(j<n){
            if(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            else{
                st.insert(s[j++]);
                ans = max(ans, j-i);
            }
        }   
        return ans;
    }
};