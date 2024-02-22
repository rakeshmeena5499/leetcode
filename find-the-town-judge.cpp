class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);
        for (auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            outdegree[a]++;
            indegree[b]++;
        }
        for (int i=1;i<=n; i++) {
            if (indegree[i] == n-1 && outdegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};