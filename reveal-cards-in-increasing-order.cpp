class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        sort(deck.begin(), deck.end());
        vector<int> res(n, 0);
        for(int i=0;i<n;i++){
            res[q.front()] = deck[i];
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};