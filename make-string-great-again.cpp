class Solution {
public:
    bool check(char a, char b) {
        return (a != b) && (tolower(a) == tolower(b));
    }

    string makeGood(string s) {
        stack<char> st;
        for(char ch : s){
            int flag = 0;
            if(!st.empty()){
                char topChar = st.top();
                if(check(topChar, ch)){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
            else{
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};