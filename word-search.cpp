class Solution {
public:
    bool solve(vector<vector<char>>& board, int index, int i, int j, string word){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index]){
            return false;
        }
        if(index == word.size()-1)
            return true;
        board[i][j] = '#';
        if(solve(board, index+1, i+1, j, word) || solve(board, index+1, i-1, j, word) || solve(board, index+1, i, j+1, word) || solve(board, index+1, i, j-1, word)){
            return true;
        }
        board[i][j] = word[index];
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(solve(board, 0, i, j, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};