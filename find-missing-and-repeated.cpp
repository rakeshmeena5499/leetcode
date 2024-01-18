class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = 0;
        long long totalSq = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                total += grid[i][j];
                totalSq += grid[i][j]*grid[i][j];
            }
        }
        long long N = n*n;
        vector<int> res;
        long long c1 = total - N*(N+1)/2;               // count diff of total sum and sum of n^2 elements
        long long c2 = totalSq - (N*(N+1)*(2*N+1))/6;   // count diff of square of elements and square sum of n^2 elements
        res.push_back((c2/c1 + c1)/2);                  // two equations two variables
        res.push_back((int)(c2/c1 - c1)/2);
        return res;
        // vector<int> res(2, 0);
        // vector<int> freq((n*n)+1, 0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         freq[grid[i][j]]++;
        //     }
        // }
        // for(int i=1;i<freq.size();i++){
        //     if(freq[i] == 2){
        //         res[0] = i;
        //     }
        //     if(freq[i] == 0){
        //         res[1] = i;
        //     }
        // }
        // return res;
    }
};