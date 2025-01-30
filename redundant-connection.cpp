class Solution {
private:
    int findParent(vector<int>& parent, int node){
        while(parent[node]!=node){
            node = parent[node];
        }
        return node;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n+1, 0);
        for(int i=1;i<=n;i++){
            parents[i] = i;
        }
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int rootU = findParent(parents, u);
            int rootV = findParent(parents, v);
            if(rootU == rootV){
                return edge;
            }
            parents[rootU] = rootV;
        }
        return {};
    }
};