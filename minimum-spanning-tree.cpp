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

class Solution{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        // Prim's Algorithm
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // vector<int> vis(V, 0);
        // pq.push({0, 0});
        // int mst = 0;
        // while(!pq.empty()){
        //     int wt = pq.top().first;    // Greedily takes the minimum weight edges to each neighbour from the 0th node using PQ
        //     int node = pq.top().second;
        //     pq.pop();
        //     if(vis[node] == 1)
        //         continue;
        //     vis[node] = 1;
        //     mst+=wt;
        //     for(auto it : adj[node]){
        //         int adjNode = it[0];
        //         int edgeWt = it[1];
        //         if(!vis[adjNode]){
        //             pq.push({edgeWt, adjNode});
        //         }
        //     }
        // }
        // return mst;


        // Kruskal's Algorithm
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int wt = it[1];
                int adjNode = it[0];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        int mst = 0;
        DisjointSet ds(V);
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findParent(u) != ds.findParent(v)){   // We only add edges in our DS if two nodes are not already connected
                mst += wt;
                ds.unionBySize(u, v);
            }
        }
        return mst;
    }
};