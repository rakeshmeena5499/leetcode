class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int uParent = findParent(u);
        int vParent = findParent(v);
        if(uParent == vParent)
            return;
        if(rank[uParent] < rank[vParent]){
            parent[uParent] = vParent;
        }
        else if(rank[vParent] < rank[uParent]){
            parent[vParent] = uParent;
        }
        else{
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }

    void unionBySize(int u, int v){
        int uParent = findParent(u);
        int vParent = findParent(v);
        if(uParent == vParent)
            return;
        if(size[uParent] < size[vParent]){
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else{
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

class Solution {
  private:
    bool isValid(int i, int j, int n){
        return (i>=0 && i<n && j>=0 && j<n);
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int i=0;i<4;i++){
                    int newR = row + dr[i];
                    int newC = col + dc[i];
                    if(isValid(newR, newC, n) && grid[newR][newC] == 1){
                        int nodeNum = row*n + col;
                        int adjNodeNum = newR*n + newC;
                        ds.unionBySize(nodeNum, adjNodeNum);
                    }
                }
            }
        }
        int mx = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 1)
                    continue;
                set<int> components;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int i=0;i<4;i++){
                    int newR = row + dr[i];
                    int newC = col + dc[i];
                    if(isValid(newR, newC, n)){
                        if(grid[newR][newC] == 1){
                            components.insert(ds.findParent(newR*n + newC));
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it : components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx = max(mx, ds.size[ds.findParent(i)]);
        }
        return mx;
    }
};