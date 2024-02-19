class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
           n = n&(n-1);
           ans++;
        }
        return ans;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1;i<=n;i++){
            ans[i] = hammingWeight(i);
        }    
        return ans;
    }
};