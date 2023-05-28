class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<set<int>> row(n), col(n), box(n);
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                char value = board[r][c];
                if(value=='.')
                    continue;
                int val = value - '0';
                int idx = (r/3)*3+c/3;
                if(row[r].count(val) || col[c].count(val) || box[idx].count(val))
                    return false;
                row[r].insert(val);
                col[c].insert(val);
                box[idx].insert(val);
            }
        }
        return true;      
    }
};