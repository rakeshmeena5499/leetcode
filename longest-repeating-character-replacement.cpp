class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int start = 0, end = 0;
        int n = s.size();
        int maxCount = 0;
        vector<int> freq(26, 0);
        for(;end<n;end++){
            freq[s[end] - 'A']++;
            maxCount = max(maxCount, freq[s[end] - 'A']);
            if(end - start + 1 - maxCount > k){         // If our window size - max frequency char becomes greater than k
                freq[s[start] - 'A']--;                 // we need to reduce the window from left side
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};