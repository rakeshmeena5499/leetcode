class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countFresh = 0;
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1)
                    countFresh++;
            }
        }
        int time = 0;
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};
        int cnt = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currTime = q.front().second;
            q.pop();
            time = max(time, currTime);
            for(int i=0;i<4;i++){
                int nrow = row + rows[i];
                int ncol = col + cols[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    vis[nrow][ncol]!=2 && grid[nrow][ncol] == 1){
                        vis[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, currTime+1});
                        cnt++;
                    }
            }
        }
        if(cnt!=countFresh)
            return -1;
        return time;
    }
};