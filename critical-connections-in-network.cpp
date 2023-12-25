class Solution {
private:
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int time[], int low[], vector<vector<int>>& bridges){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent)
                continue;
            if(vis[it] == 0){
                dfs(it, node, vis, adj, time, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > time[node])
                    bridges.push_back({it, node});
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n, 0);
        int time[n];
        int low[n];
        vector<int> adj[n];
        vector<vector<int>> bridges;
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, -1, vis, adj, time, low, bridges);
        return bridges;
    }
};