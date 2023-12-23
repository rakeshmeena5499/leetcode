#include <bits/stdc++.h>
using namespace std;

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

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else{
        cout << "Not same\n"; 
    }

    ds.unionBySize(3, 7); 

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else{
        cout << "Not same\n"; 
    }

	return 0;
}
