#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool detectCycleBFS(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neighbour : adj[node]){
                if(!vis[neighbour]){
                    vis[neighbour] = 1;
                    q.push({neighbour, node});
                }
                else if(parent != neighbour){
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycleDFS(int src, int parent, vector<int> adj[], int vis[]){
        vis[src] = 1;
        for(auto it : adj[src]){
            if(!vis[it]){
                if(detectCycleDFS(it, src, adj, vis))
                    return true;
            }
            else if(it != parent)
                return true;
        }
        return false; 
    }

  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detectCycleDFS(i, -1, adj, vis)) return true; 
            }
        }
        return false; 
    }
};

int main() {
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}