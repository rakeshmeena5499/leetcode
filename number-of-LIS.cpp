class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), count(n, 1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];            // Inherit the count of LIS from the prev 
                }
                else if(arr[i] > arr[j] && dp[i] == dp[j] + 1){
                    count[i] += count[j];           // Add the count of LIS from the prev
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                ans += count[i];
            }
        }
        return ans;
    }
};