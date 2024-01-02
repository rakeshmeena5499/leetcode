class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> st;
        for(string word : wordList){
            st.insert(word);
        }
        if(st.find(endWord)==st.end())
            return 0;
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                string word = q.front();
                q.pop();
                if(word == endWord){
                    return ans;
                }
                for(int j=0;j<word.size();j++){
                    string temp = word;
                    for(char ch = 'a';ch<='z';ch++){
                        temp[j] = ch;
                        if(st.find(temp)!=st.end()){
                            st.erase(temp);
                            q.push(temp);
                        }
                    }
                }   
            }
            ans++;
        }
        return 0;
    }
};