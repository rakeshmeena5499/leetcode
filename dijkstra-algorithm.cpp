class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        while(!pq.empty()){
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto itr : adj[node]){
                int edgeWeight = itr[1];
                int adjNode = itr[0];
                if((currDist + edgeWeight) < dist[adjNode]){
                    dist[adjNode] = currDist + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};