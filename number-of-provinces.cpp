class DisjointSet{
    vector<int> rank, parent, size;
    public:
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
        if(rank[uParent] < rank[vParent]){
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else{
            parent[vParent] = uParent;
            size[uParent] += vParent;
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        int ans = 0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1){
                    ds.unionBySize(i, j);   // First find ultimate parents of all nodes which are connected
                }
            }
        }
        for(int i=0;i<V;i++){
            if(ds.findParent(i) == i)       // If a node is the ultimate parent of itself then it is a unique component
                ans++;
        }
        return ans;
    }
};