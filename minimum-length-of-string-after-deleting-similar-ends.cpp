class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int low = 0, high = n - 1;
        while(low < high && s[low] == s[high]){
            char c = s[low];
            while(s[low] == c && low <= high){
                low++;
            }
            while(s[high] == c && low <= high){
                high--;
            }
        }
        return high - low + 1;
    }
};