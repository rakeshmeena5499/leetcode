class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int n : nums){
            if(!st.count(n-1)){
                int length = 1;
                while(st.count(n+length)){
                    length++;
                }
                longest = max(longest, length);
            }
        }      
        return longest;
    }
};