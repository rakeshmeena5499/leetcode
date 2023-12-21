class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i=0;i<V;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u]!=1e8 && dist[u] + wt < dist[v]){     // dist[u] should be reachable then only we will update it
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[u] + wt < dist[v])          // If we're still be able to update dist[u] on Nth iteration 
                return {-1};                                    // there exists a negative weight cycle in the graph
        }
        return dist;
    }
};