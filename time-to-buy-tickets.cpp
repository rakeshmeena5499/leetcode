class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i], i});    
        }
        int ans = 0;
        while(!q.empty()){
            ans++;
            auto front = q.front();
            q.pop();
            if(front.first == 1 && front.second == k){
                break;
            }
            if(front.first != 1)
                q.push({front.first-1, front.second});
        }
        return ans;
    }
};