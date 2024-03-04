class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int ans = 0;
        int lo = 0, hi = n-1;
        while(lo <= hi){
            if(tokens[lo] <= power){
                power -= tokens[lo++];
                ans++;
            }
            else if(lo < hi && ans > 0){
                power += tokens[hi--];
                ans--;
            }
            else{
                return ans;
            }
        }      
        return ans;
    }
};