class Solution {
public:
    int longestBitonicSubsequence(vector<int>& arr, int n){
    vector<int> dp1(n, 1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && 1 + dp1[j] > dp1[i]){
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    vector<int> dp2(n, 1);
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i] > arr[j] && 1 + dp2[j] > dp2[i]){
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int maxi = 1;
    for(int i=0;i<n;i++){
        if(dp1[i]>1 && dp2[i]>1){       // This check ensures that we don't consider strictly increasing/decreasing subsequence
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
    }
    return maxi;
}
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        return n - longestBitonicSubsequence(nums, n);
    }
};