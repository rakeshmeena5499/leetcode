class Solution{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        int mst = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node] == 1)
                continue;
            vis[node] = 1;
            mst+=wt;
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!vis[adjNode]){
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return mst;
    }
};