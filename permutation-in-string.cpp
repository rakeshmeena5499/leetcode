class Solution {
public:
    bool match(vector<int>& mp1, vector<int>& mp2){
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26, 0);
        if(s1.size()>s2.size())
            return false;
        for(int i=0;i<s1.size();i++){
            mp1[s1[i]-'a']++;
        }    
        for(int i=0;i<=s2.size()-s1.size();i++){
            vector<int> mp2(26, 0);
            for(int j=0;j<s1.size();j++){
                mp2[s2[i+j]-'a']++;
            }
            if(match(mp1, mp2))
                return true;
        }
        return false;
    }
};