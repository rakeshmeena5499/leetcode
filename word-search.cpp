class Solution {
public:
    bool solve(vector<vector<char>>& board, int index, string word, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[index])
            return false;
        if(index == word.size()-1)
            return true;
        board[i][j] = '#';
        if(solve(board, index+1, word, i+1, j, m, n) || solve(board, index+1, word, i-1, j, m, n) || solve(board, index+1, word, i, j+1, m, n) || solve(board, index+1, word, i, j-1, m, n))
            return true;
        board[i][j] = word[index];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0])
                    if(solve(board, 0, word, i, j, m, n))
                        return true;
            }
        }
        return false;
    }
};