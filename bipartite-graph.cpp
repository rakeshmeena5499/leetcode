class Solution {
public:
    bool checkDFS(int node, int col, vector<vector<int>>& graph, vector<int>& color){
        color[node] = col;
        for(auto it : graph[node]){
            if(!color[it]){
                if(!checkDFS(it, -col, graph, color)){
                    return false;
                }
            }
            else if(color[it] == col)
                return false;
        }
        return true;
    }

    bool checkBFS(int node, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it : graph[front]){
                if(!color[it]){
                    q.push(it);
                    color[it] = -color[front];
                }
                else if(color[it] == color[front])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for(int i=0;i<n;i++){
            if(!color[i]){
                if(!checkBFS(i, graph, color))  // checkDFS(i, 1, graph, color) can be used with starting color given as 
                    return false;
            }
        }
        return true;
    }
};