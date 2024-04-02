class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m){
            return false;
        }
        vector<int> freqS(200, 0), freqT(200, 0);
        for(int i=0;i<n;i++){
            char cs = s[i];
            char ct = t[i];
            if(freqS[cs] != freqT[ct]){
                return false;
            }
            freqS[cs] = i+1;
            freqT[ct] = i+1;
        }
        return true;
    }
};