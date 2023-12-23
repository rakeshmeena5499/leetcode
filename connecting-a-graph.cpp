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
    int Solve(int n, vector<vector<int>>& edge) {
        int extraEdges = 0;
        int numberOfComponents = 0;
        DisjointSet ds(n);
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u, v);
            }
            else{
                extraEdges++;
            }
        }

        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i){
                numberOfComponents++;
            }
        }
        return (extraEdges>=numberOfComponents-1) ? numberOfComponents-1 : -1;
    }
};