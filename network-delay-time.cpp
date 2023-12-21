class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e8);
        dist[k] = 0;
        // for(int i=1;i<n;i++){
        //     for(auto& it : times){
        //         int u = it[0];
        //         int v = it[1];
        //         int wt = it[2];
        //         if(dist[u]!=1e8 && dist[u] + wt < dist[v]){
        //             dist[v] = dist[u] + wt;
        //         }
        //     }
        // }
        // int maxwait = 0;
        // for (int i = 1; i <= n; i++)
        //     maxwait = max(maxwait, dist[i]);
        // return maxwait == 1e8 ? -1 : maxwait;
        
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto& it : times){
            graph[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int node = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            for(auto it : graph[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxwait = 0;
        for (int i = 1; i <= n; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == 1e8 ? -1 : maxwait;
    }
};