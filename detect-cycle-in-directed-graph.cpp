class Solution {
  private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){                   // If neighbour is visited or not
                if(dfs(it, adj, vis, pathVis) == true)
                    return true;
            }
            else if(pathVis[it] == 1){      // If neighbour is visited then check if its in the same path
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {};
        int pathVis[V] = {};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true)
                    return true;
            }
        }
        return false;
    }
};