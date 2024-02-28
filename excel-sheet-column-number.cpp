class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int temp = columnTitle[i] - 'A' + 1;
            ans = ans * 26 + temp;
        }
        return ans;
    }
};