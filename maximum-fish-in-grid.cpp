class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int& fish){
         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j] == 0)
            return;
        vis[i][j] = 1;
        fish += grid[i][j];
        solve(i-1, j, grid, vis, fish);
        solve(i+1, j, grid, vis, fish);
        solve(i, j-1, grid, vis, fish);
        solve(i, j+1, grid, vis, fish);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    int fish = 0;
                    solve(i, j, grid, vis, fish);
                    maxFish = max(maxFish, fish);
                }
            }
        }
        return maxFish;
    }
};