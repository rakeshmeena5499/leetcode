class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> lastIndex(26, 0);
        vector<int> seen(26, 0);
        stack<char> st;
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a'] = i;
        }
        for(int i=0;i<n;i++){
            int curr = s[i] - 'a';
            if(seen[curr])
                continue;
            while(!st.empty() && st.top() > curr && i < lastIndex[st.top()]){   // Keep the char in stack if its not in gonna
                seen[st.top()] = 0;                                             // come further down the array
                st.pop();
            }
            st.push(curr);
            seen[curr] = 1;
        }
        string ans = "";
        while(!st.empty()){
            ans = (char)(st.top()+'a') + ans;
            st.pop();
        }
        return ans;
    }
};