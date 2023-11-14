class Solution {
public:
    // int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
    //     if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
    //         return -1e8;
    //     if(dp[i][j1][j2]!=-1)
    //         return dp[i][j1][j2];
    //     if(i==grid.size()-1){
    //         if(j1==j2)
    //             return grid[i][j1];
    //         else
    //             return grid[i][j1] + grid[i][j2];
    //     }
    //     int maxi = 0;
    //     for(int dj1 = -1;dj1<=1;dj1++){
    //         for(int dj2 = -1;dj2<=1;dj2++){
    //             if(j1==j2)
    //                 maxi = max(maxi, grid[i][j1] + solve(i+1, j1+dj1, j2+dj2, grid, dp));
    //             else
    //                 maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1+dj1, j2+dj2, grid, dp));
    //         }
    //     }
    //     return dp[i][j1][j2] = maxi;
    // }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        // return solve(0, 0, n-1, grid, dp);

        //vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        vector<vector<int>> front(n, vector<int>(n, 0));
        vector<vector<int>> curr(n, vector<int>(n, 0));
        //Base Case
        for(int j1 = 0;j1<n;j1++){
            for(int j2 = 0;j2<n;j2++){
                if(j1==j2){
                    front[j1][j2] = grid[m-1][j1];
                }
                else{
                    front[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
                }
            }
        }
        //Tabulation with space optimized
        for(int i=m-2;i>=0;i--){
            for(int j1 = 0;j1<n;j1++){
                for(int j2 = 0;j2<n;j2++){
                    int maxi = 0;
                    for(int dj1 = -1;dj1<=1;dj1++){
                        for(int dj2 = -1;dj2<=1;dj2++){
                            int value = 0;
                            if(j1==j2)
                                value += grid[i][j1];     
                            else
                                value += grid[i][j1] + grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<n && j2 + dj2 >= 0 && j2+ dj2<n)
                                value += front[j1+dj1][j2+dj2];
                            else
                                value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][n-1];
    }
};