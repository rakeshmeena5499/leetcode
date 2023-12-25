class Solution {
  private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, int time[], int low[],
                vector<int>& marked, vector<int> adj[]){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent)
                continue;
            if(vis[it] == 0){
                dfs(it, node, vis, time, low, marked, adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= time[node] && parent!=-1){
                    marked[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], time[it]);
            }
        }
        if(child>1 && parent==-1){
            marked[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V, 0);
        int time[V];
        int low[V];
        vector<int> marked(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, -1, vis, time, low, marked, adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(marked[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
};